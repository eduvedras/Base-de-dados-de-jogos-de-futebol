#ifndef _HASHEQUIPAS_H
#define _HASHEQUIPAS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*constantes*/
#define MAX_NAME 1024
#define TAM_TAB 1049

/*estrutura equipa que contem o ponteiro para o nome da equipa e 
para o seu numero de vitorias*/
typedef struct equipa{
    char *nome_eq;
    int vitorias;
}*pequipa;/*pequipa e um ponteiro para equipa*/

/*estrutura que representa um no contendo um ponteiro para uma equipa e next*/
typedef struct node_equipa{
    pequipa p_equipa;
    struct node_equipa *next;
}*link_eq;/*link_eq e um ponteiro para node_equipa*/

pequipa novaequipa(char* nome_eq,int vitorias);
link_eq *init_sist_equipas();
void insert_sist_equipas(link_eq *sist_equipas,pequipa p_equipa);
link_eq search_sist_equipas(link_eq *sist_equipas,char* nome_eq);
void destroy_sist_equipas(link_eq *sist_equipas);
void adiciona_vitoria(link_eq *sist_equipas,char * nome_eq);
void remove_vitoria(link_eq *sist_equipas,char * nome_eq);

#endif