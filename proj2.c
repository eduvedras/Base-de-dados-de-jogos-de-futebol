/*
 * Ficheiro:  proj2.c
 * Autor:  Eduardo Miranda 95569 LEIC-A
 * Descricao: Sistema de gestao de uma base de dados de jogos de 
 * futebol amigaveis
*/

#include "hashtable.h"
#include "hashequipas.h"
#include "linked_list_j.h"
#define TAM_ARR 100

/*funcao auxiliar que retorna o valor da comparacao de duas strings,
utilizada no qsort*/
int compara_string(const void *arg1, const void *arg2) { 
    /*como os argumentos sao void temos que transformar em chars*/
    const char **iarg1 = (const char **)arg1;
    const char **iarg2 = (const char **)arg2;
    return strcmp(*iarg1, *iarg2);
} 

void a(link *sist_jogos,link_eq *sist_equipas,LinkedList_j lista_jogos,int NL);

void A(link_eq *sist_equipas, int NL);

void l(LinkedList_j lista_jogos, int NL);

void p(link *sist_jogos, int NL);

void P(link_eq *sist_equipas, int NL);

void r(link *sist_jogos,link_eq *sist_equipas,LinkedList_j lista_jogos,int NL);

void s(link *sist_jogos, link_eq *sist_equipas,int NL);

void g(link_eq * sist_equipas,int NL);

int main(){
    char c;
    int NL;
    link *sist_jogos;
    link_eq *sist_equipas;
    LinkedList_j lista_jogos;
    /*iniciar as tabelas*/
    lista_jogos=lista_jogos_init();
    sist_jogos=init_sist_jogos();
    sist_equipas=init_sist_equipas();
    NL=0;
    c=getchar();
    while(c!='x'){
        switch(c){
            case 'a':
                NL=NL+1;
                a(sist_jogos,sist_equipas,lista_jogos,NL);
                break;
            case 'A':
                NL=NL+1;
                A(sist_equipas,NL);
                break;
            case 'l':
                NL=NL+1;
                l(lista_jogos,NL);
                break;
            case 'p':
                NL=NL+1;
                p(sist_jogos,NL);
                break;
            case 'P':
                NL=NL+1;
                P(sist_equipas,NL);
                break;
            case 'r':
                NL=NL+1;
                r(sist_jogos,sist_equipas,lista_jogos,NL);
                break;
            case 's':
                NL=NL+1;
                s(sist_jogos,sist_equipas,NL);
                break;
            case 'g':
                NL=NL+1;
                g(sist_equipas,NL);
                break;
        }
        c=getchar();
    }
    destroy_list_j(lista_jogos);
    destroy_sist_jogos(sist_jogos);
    destroy_sist_equipas(sist_equipas);
    return 0;
}

/*funcao que adiciona novo jogo ao sistema*/
void a(link *sist_jogos,link_eq *sist_equipas,LinkedList_j lista_jogos, int NL){
    pjogo p_jogo;
    char nome[MAX_NAME],equipa1[MAX_NAME],equipa2[MAX_NAME];
    int score1,score2;
    scanf(" %[^:\n]:%[^:\n]:%[^:\n]:%d:%d",nome,equipa1,equipa2,&score1,&score2);
    if(search_sist_jogos(sist_jogos,nome)!=NULL){
        printf("%d Jogo existente.\n", NL);
        return;
    }
    else if(search_sist_equipas(sist_equipas,equipa1)==NULL 
        || search_sist_equipas(sist_equipas,equipa2)==NULL){
        printf("%d Equipa inexistente.\n", NL);
        return;
    }
    else{
        /*insere o jogo no sist_jogos e lista_jogos*/
        p_jogo=novojogo(nome,equipa1,equipa2,score1,score2);
        insert_sist_jogos(sist_jogos,p_jogo);
        adiciona_j(lista_jogos,p_jogo);
        /*adiciona uma vitoria a equipa vitoriosa*/
        if((p_jogo->score1) > (p_jogo->score2)){
            adiciona_vitoria(sist_equipas,p_jogo->equipa1);
        }
        else if((p_jogo->score1) < (p_jogo->score2)){
            adiciona_vitoria(sist_equipas,p_jogo->equipa2);
        }
    }
}

/*funcao que adiciona uma nova equipa ao sistema*/
void A(link_eq *sist_equipas, int NL){
    pequipa p_equipa;
    char nome_equipa[MAX_NAME];
    int vitorias;
    vitorias=0;
    scanf(" %[^:\n]", nome_equipa);
    if (search_sist_equipas(sist_equipas,nome_equipa)!=NULL){
        printf("%d Equipa existente.\n", NL);
        return;
    }
    else{
        p_equipa=novaequipa(nome_equipa,vitorias);
        insert_sist_equipas(sist_equipas,p_equipa);
    }
}

/*funcao que lista todos os jogos por ordem de entrada*/
void l(LinkedList_j lista_jogos, int NL){
    link tmp;
    tmp = lista_jogos->head;
    if(lista_jogos->head==NULL){
        return;
    }
    else{
        while(tmp!=NULL){
            printf("%d %s %s %s %d %d\n",NL,tmp->p_jogo->nome,tmp->p_jogo->equipa1,
                tmp->p_jogo->equipa2, tmp->p_jogo->score1, tmp->p_jogo->score2);
            tmp=tmp->next;
        }
    }
}

/*funcao que procura um jogo no sistema*/
void p(link *sist_jogos, int NL){
    link res;
    char nome[MAX_NAME];
    scanf(" %[^:\n]",nome);
    res=search_sist_jogos(sist_jogos,nome);
    if(res==NULL){
        printf("%d Jogo inexistente.\n", NL);
        return;
    }
    else{
        printf("%d %s %s %s %d %d\n",NL,res->p_jogo->nome,res->p_jogo->equipa1,
            res->p_jogo->equipa2,res->p_jogo->score1,res->p_jogo->score2);
    }
}

/*funcao que procura uma equipa no sistema*/
void P(link_eq *sist_equipas, int NL){
    link_eq res;
    char nome_equipa[MAX_NAME];
    scanf(" %[^:\n]",nome_equipa);
    res=search_sist_equipas(sist_equipas,nome_equipa);
    if(res==NULL){
        printf("%d Equipa inexistente.\n",NL);
        return;
    }
    else{
        printf("%d %s %d\n",NL,res->p_equipa->nome_eq, res->p_equipa->vitorias);
    }
}

/*funcao que remove um jogo do sistema*/
void r(link *sist_jogos, link_eq *sist_equipas,LinkedList_j lista_jogos,int NL){
    link jogo_node;
    char nome_jogo[MAX_NAME];
    scanf(" %[^:\n]",nome_jogo);
    jogo_node=search_sist_jogos(sist_jogos,nome_jogo);
    if(jogo_node==NULL){
        printf("%d Jogo inexistente.\n",NL);
        return;
    }
    else{
        if(jogo_node->p_jogo->score1 > jogo_node->p_jogo->score2){
            remove_vitoria(sist_equipas,jogo_node->p_jogo->equipa1);
        }
        else if(jogo_node->p_jogo->score1 < jogo_node->p_jogo->score2){
            remove_vitoria(sist_equipas,jogo_node->p_jogo->equipa2);
        }
        /*remove no sist_jogos e na lista_jogos*/
        remove_elem_j(lista_jogos,nome_jogo);
        delete_sist_jogos(sist_jogos,jogo_node->p_jogo);
    }
}

/*funcao que altera o score de um jogo*/
void s(link *sist_jogos, link_eq *sist_equipas,int NL){
    link jogo_node;
    char nome[MAX_NAME];
    int score1,score2;
    scanf(" %[^:\n]:%d:%d",nome,&score1,&score2);
    jogo_node=search_sist_jogos(sist_jogos,nome);
    if(jogo_node==NULL){
        printf("%d Jogo inexistente.\n",NL);
        return;
    }
    else{
        if(score1 > score2 && 
            jogo_node->p_jogo->score1 == jogo_node->p_jogo->score2){
            adiciona_vitoria(sist_equipas,jogo_node->p_jogo->equipa1);
        }
        else if(score1 > score2 && 
            jogo_node->p_jogo->score1 < jogo_node->p_jogo->score2){
            adiciona_vitoria(sist_equipas,jogo_node->p_jogo->equipa1);
            remove_vitoria(sist_equipas,jogo_node->p_jogo->equipa2);
        }
        else if(score1==score2 && 
            jogo_node->p_jogo->score1 > jogo_node->p_jogo->score2){
            remove_vitoria(sist_equipas,jogo_node->p_jogo->equipa1);
        }
        else if(score1==score2 && 
            jogo_node->p_jogo->score1 < jogo_node->p_jogo->score2){
            remove_vitoria(sist_equipas,jogo_node->p_jogo->equipa2);
        }
        else if(score1 < score2 && 
            jogo_node->p_jogo->score1 == jogo_node->p_jogo->score2){
            adiciona_vitoria(sist_equipas,jogo_node->p_jogo->equipa2);
        }
        else if(score1 < score2 && 
            jogo_node->p_jogo->score1 > jogo_node->p_jogo->score2){
            adiciona_vitoria(sist_equipas,jogo_node->p_jogo->equipa2);
            remove_vitoria(sist_equipas,jogo_node->p_jogo->equipa1);
        }
        /*altera o score no sist_jogos e lista_jogos*/
        jogo_node->p_jogo->score1=score1;
        jogo_node->p_jogo->score2=score2;
    }
}

/*funcao que encontra e lista as equipas com mais vitorias*/
void g(link_eq * sist_equipas,int NL){
    int maior_vit,a,i;
    char *lista_eq[TAM_ARR];
    link_eq tmp;
    a=0;
    maior_vit=0;
    /*ciclo que encontra o numero mais alto de vitorias*/
    for(i=0; i< TAM_TAB; i++){
        if (sist_equipas[i] != NULL){
            a=1;
            tmp=sist_equipas[i];
            while(tmp!=NULL){
                if(tmp->p_equipa->vitorias > maior_vit){
                    maior_vit=tmp->p_equipa->vitorias;
                }
                tmp=tmp->next;
            }
        }
    }
    /*verifica se existe alguma equipa no sist_equipas*/
    if(a==0){
        return;
    }
    a=0;
    /*ciclo que encontra as equipas com o numero mais alto de vitorias e
    adiciona-as a lista_eq*/
    for(i=0; i< TAM_TAB; i++){
        if (sist_equipas[i] != NULL){
            tmp=sist_equipas[i];
            while(tmp!=NULL){
                if(tmp->p_equipa->vitorias == maior_vit){
                    lista_eq[a]=
                        (char*)malloc(sizeof(char)*
                            (strlen(tmp->p_equipa->nome_eq)+1));
                    strcpy(lista_eq[a],tmp->p_equipa->nome_eq);
                    /*variavel que guarda o numero de equipas inseridas*/
                    a=a+1;
                }
                tmp=tmp->next;
            }
        }
    }
    qsort(lista_eq,a,sizeof(char*),compara_string);
    printf("%d Melhores %d\n",NL,maior_vit);
    for(i=0;i<a;i++){
        printf("%d * %s\n",NL,lista_eq[i]);
        free(lista_eq[i]);
    }
}