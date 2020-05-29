#ifndef _LINKED_LIST_J_H
#define _LINKED_LIST_J_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*inclui hashtable.h de modo a poder usar as suas funcoes*/
#include "hashtable.h"

/*estrutura que representa o no que contem o inicio e o fim de 
uma lista ligada*/
typedef struct MasterNode {
	link head;
	link tail;
}* LinkedList_j;

LinkedList_j lista_jogos_init();
void adiciona_j(LinkedList_j lista, pjogo p_jogo);
void remove_elem_j(LinkedList_j lista, char*nome);
void destroy_list_j(LinkedList_j lista);

#endif