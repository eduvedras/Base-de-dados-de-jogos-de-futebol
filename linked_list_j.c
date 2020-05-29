#include "linked_list_j.h"

/*funcao que inicia a lista_jogos alocando memoria
e colocando tudo a NULL*/
LinkedList_j lista_jogos_init() {
	LinkedList_j lista;
	lista = malloc(sizeof(struct MasterNode));
	lista->head = NULL;
	lista->tail = NULL;
	return lista;
}
/*funcao que adiciona um node no final da lista*/
link adiciona_node_depois_j(link ant, pjogo p_jogo) {
    link novo;
	if (ant == NULL){ 
		return newnode(ant, p_jogo);
	}
	else{
		novo = malloc(sizeof(struct node));
		/*coloca no final da lista*/
		novo->p_jogo = p_jogo;
		novo->next = ant->next;
		ant->next = novo;
		return novo;
	}
}

/*funcao que adiciona um jogo a lista*/
void adiciona_j(LinkedList_j lista, pjogo p_jogo) {
	link newNode; 
	newNode = adiciona_node_depois_j(lista->tail, p_jogo);
	lista->tail = newNode;
	if (lista->head == NULL){
		lista->head = newNode;
	}
}

/*funcao que remove um jogo da lista_jogos dado um nome*/
void remove_elem_j(LinkedList_j lista, char *nome) {
	link atual, ant;
	for (atual = lista->head, ant = NULL; atual != NULL; ant = atual,
		atual = atual->next){
        if(strcmp(atual->p_jogo->nome,nome)==0){
			/*se o elemento for o ultimo
			tail passa a ser o anterior*/
            if (atual == lista->tail){
				lista->tail = ant;
			}
			/*se o elemento for o primeiro
			head passa a ser o seguinte*/
            if (atual == lista->head){
				lista->head = atual->next;
			}
            else{ 
				ant->next = atual->next;
			}
			free(atual);
            return;
        }
	}
}

/*funcao que destroi a lista_jogos*/
void destroy_list_j(LinkedList_j lista) {
	link atual, aux;
	if (lista == NULL){
		return;
	}
	if (lista->head==NULL){
        return;
    }
	for (atual = lista->head, aux = lista->head->next; atual!=NULL;
		aux = atual->next, free(atual), atual = aux){}
	free(lista);
}