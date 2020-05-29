#include"hashtable.h"

/*funcao que cria um novo jogo*/
pjogo novojogo(char* nome,char* equipa1, char* equipa2,int score1,int score2){
    pjogo p_jogo;
    p_jogo=(pjogo)malloc(sizeof(struct jogo));
    p_jogo->nome=(char*)malloc(sizeof(char)*(strlen(nome)+1));
    p_jogo->equipa1=(char*)malloc(sizeof(char)*(strlen(equipa1)+1));
    p_jogo->equipa2=(char*)malloc(sizeof(char)*(strlen(equipa2)+1));
    strcpy(p_jogo->nome,nome);
    strcpy(p_jogo->equipa1,equipa1);
    strcpy(p_jogo->equipa2,equipa2);
    p_jogo->score1=score1;
    p_jogo->score2=score2;
    return p_jogo;
}

/*funcao que apaga um jogo libertando a memoria alocada para ele*/
void deletejogo(pjogo p_jogo){
    if(p_jogo!=NULL){
        free(p_jogo->nome);
        free(p_jogo->equipa1);
        free(p_jogo->equipa2);
        free(p_jogo);
    }
}

/*funcao que apaga um no apagando o jogo e depois 
libertando a memoria para este no*/
void deletenode(link node){
    if(node!=NULL){
        deletejogo(node->p_jogo);
        free(node);
    }
}

/*funcao que inicia o sistema de jogos alocando memoria
e colocando tudo a NULL*/
link *init_sist_jogos(){
    int i;
    link *sist_jogos;
    sist_jogos = (link*) malloc(TAM_TAB*sizeof(link));
    for(i=0;i<TAM_TAB;i++){
        sist_jogos[i]=NULL;
    }
    return sist_jogos;
}

/*funcao que destroi uma lista*/
void destroy_list(link head) {
    link atual, aux;
	if (head==NULL){
        return;
    }
	for (atual = head, aux = head->next; atual!=NULL; aux = atual->next,
        deletenode(atual), atual = aux){}
}

/*funcao que destroi sistema de jogos*/
void destroy_sist_jogos(link *sist_jogos){
    int i;
	for (i = 0; i < TAM_TAB; i++) {
		destroy_list(sist_jogos[i]);
	}
	free(sist_jogos);
}

/*funcao que retorna um valor quando e dado um nome*/
unsigned int hash(char *name){
    int length = strlen(name);
    int i;
    unsigned int hash_value;
    hash_value=0;
    for(i=0;i<length;i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]);
        hash_value = hash_value % TAM_TAB;
    }
    return hash_value;
}

/*funcao que cria um novo no dado um jogo colocando-o no inicio da lista*/
link newnode(link head,pjogo p_jogo){
    link res;
    res=(link)malloc(sizeof(struct node));
    res->p_jogo=p_jogo;
    res->next=head;
    return res;
}

/*funcao que insere um jogo no sist_jogos*/
void insert_sist_jogos(link *sist_jogos,pjogo p_jogo){
    int i;
    i = hash(p_jogo->nome);
    sist_jogos[i]=newnode(sist_jogos[i],p_jogo);
}

/*funcao que procura numa lista um jogo*/
link search_lista(link head,char*nome){
    link tmp;
    tmp = head;
    /*enquanto nao encontrar o link avanca depois quando encontra 
    retorna-o*/
    while(tmp!=NULL && strcmp(tmp->p_jogo->nome,nome)!=0){
        tmp=tmp->next;
    }
    return tmp;
}

/*funcao que procura um jogo no sist_jogos*/
link search_sist_jogos(link *sist_jogos,char * nome){
    int i;
    link tmp;
    i=hash(nome);
    tmp=search_lista(sist_jogos[i],nome);
    return tmp;
}

/*funcao que remove um jogo de uma lista*/
link remove_elemento(link head, pjogo pjogo){
    link tmp, ant;
    for(tmp = head, ant = NULL; tmp != NULL;ant = tmp, tmp = tmp->next) {
        if(strcmp(tmp->p_jogo->nome, pjogo->nome) == 0) {
            /*se o elemento for o primeiro
			head passa a ser o seguinte*/
            if(tmp == head){
                head = tmp->next;
            }
            else{
                ant->next = tmp->next;
            }
            deletenode(tmp);
            return head;
        }
    }
    return head;
}

/*funcao que remove um jogo do sist_jogos*/
void delete_sist_jogos(link *sist_jogos,pjogo p_jogo){
    int i;
    i = hash(p_jogo->nome);
    sist_jogos[i] = remove_elemento(sist_jogos[i],p_jogo);
}