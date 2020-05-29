#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*constantes*/
#define MAX_NAME 1024
#define TAM_TAB 1049

/*estrutura que representa um jogo*/
typedef struct jogo{
    char *nome;
    char *equipa1;
    char *equipa2;
    int score1;
    int score2;
}*pjogo;/*pjogo e um ponteiro para jogo*/

/*estrutura que representa um no contendo um ponteiro para um jogo e next*/
typedef struct node{
    pjogo p_jogo;
    struct node *next;
}*link;/*link e um ponteiro para node*/

pjogo novojogo(char* nome,char* equipa1, char* equipa2,int score1,int score2);
link *init_sist_jogos();
void insert_sist_jogos(link *sist_jogos,pjogo p_jogo);
link search_sist_jogos(link *sist_jogos,char * nome);
void delete_sist_jogos(link *sist_jogos,pjogo p_jogo);
void destroy_sist_jogos(link *sist_jogos);
link newnode(link head,pjogo p_jogo);

#endif