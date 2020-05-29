#include"hashequipas.h"

/*funcao que cria uma nova equipa*/
pequipa novaequipa(char* nome_eq,int vitorias){
    pequipa p_equipa;
    p_equipa=(pequipa)malloc(sizeof(struct equipa));
    p_equipa->nome_eq=(char*)malloc(sizeof(char)*(strlen(nome_eq)+1));
    strcpy(p_equipa->nome_eq,nome_eq);
    p_equipa->vitorias=vitorias;
    return p_equipa;
}

/*funcao que apaga uma equipa dando free a memoria alocada*/
void delete_equipa(pequipa p_equipa){
    if(p_equipa!=NULL){
        free(p_equipa->nome_eq);
        free(p_equipa);
    }
}

/*apaga um link_eq apagando primeiro a equipa de depois liberta a memoria
alocada para este link_eq*/
void delete_link_eq(link_eq node_eq){
    delete_equipa(node_eq->p_equipa);
    free(node_eq);
}

/*funcao que inicia o sistema de equipas alocando memoria
e colocando tudo a NULL*/
link_eq *init_sist_equipas(){
    int i;
    link_eq *sist_equipas;
    sist_equipas = (link_eq*) malloc(TAM_TAB*sizeof(link_eq));
    for(i=0;i<TAM_TAB;i++){
        sist_equipas[i]=NULL;
    }
    return sist_equipas;
}
/*funcao que destroi uma lista de equipas*/ 
void destroy_list_eq(link_eq head) {
    link_eq atual, aux;
	if (head==NULL) return;
	for (atual = head, aux = head->next; atual!=NULL; aux = atual->next,
        delete_link_eq(atual), atual = aux){}
}

/*funcao que destroi o sistema de equipas*/
void destroy_sist_equipas(link_eq *sist_equipas){
    int i;
	for (i = 0; i < TAM_TAB; i++) {
		destroy_list_eq(sist_equipas[i]);
	}
	free(sist_equipas);
}

/*funcao que retorna um valor quando e dado um nome*/
unsigned int hash_eq(char *name){
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

/*funcao que cria um novo link_eq dado uma equipa*/
link_eq newlink_eq(link_eq head,pequipa p_equipa){
    link_eq res;
    res=(link_eq)malloc(sizeof(struct node_equipa));
    res->p_equipa=p_equipa;
    res->next=head;
    return res;
}

/*funcao que insere uma equipa numa lista*/
link_eq insere_eq(link_eq head,pequipa p_equipa){
    link_eq aux;
    aux=newlink_eq(head,p_equipa);
    return aux;
}

/*funcao que insere uma equipa no sistema de equipas*/
void insert_sist_equipas(link_eq *sist_equipas,pequipa p_equipa){
    int i;
    i = hash_eq(p_equipa->nome_eq);
    sist_equipas[i]=insere_eq(sist_equipas[i],p_equipa);
}

/*funcao que procura uma equipa no sistema de equipas*/
link_eq search_sist_equipas(link_eq *sist_equipas,char * nome_eq){
    int i;
    link_eq tmp;
    i=hash_eq(nome_eq);
    tmp=sist_equipas[i];
    /*enquanto nao encontrar a palavra o link_eq depois quando encontra 
    retorna-o*/
    while(tmp!=NULL && strcmp(tmp->p_equipa->nome_eq,nome_eq)!=0){
        tmp=tmp->next;
    }
    return tmp;
}

/*funcao que remove uma equipa de uma lista*/
link_eq remove_elemento_eq(link_eq head, pequipa pequipa){
    link_eq tmp, ant;
    for(tmp = head, ant = NULL; tmp != NULL;ant = tmp, tmp = tmp->next) {
        if(strcmp(tmp->p_equipa->nome_eq, pequipa->nome_eq) == 0) {
            /*se o anterior for igual a head significa que o elemento
            a remover e o primeiro, logo head = tmp->next*/
            if(ant == head){
                head = tmp->next;
            }
            else{
                ant->next = tmp->next;
            }
            delete_link_eq(tmp);
            return head;
        }
    }
    return head;
}

/*funcao que remove uma equipa do sist_equipas*/
void delete_sist_equipas(link_eq *sist_equipas,pequipa p_equipa){
    int i;
    i = hash_eq(p_equipa->nome_eq);
    sist_equipas[i] = remove_elemento_eq(sist_equipas[i],p_equipa);
}

/*funcao que adiciona uma vitoria a uma equipa*/
void adiciona_vitoria(link_eq *sist_equipas,char * nome_eq){
    link_eq aux;
    aux=search_sist_equipas(sist_equipas,nome_eq);
    aux->p_equipa->vitorias = aux->p_equipa->vitorias + 1;
}

/*funcao que remove uma vitoria a uma equipa*/
void remove_vitoria(link_eq *sist_equipas,char * nome_eq){
    link_eq aux;
    aux=search_sist_equipas(sist_equipas,nome_eq);
    aux->p_equipa->vitorias = aux->p_equipa->vitorias - 1;
}