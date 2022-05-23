#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main() {
	DoubleLinkedList* MyList = NewDoubleLinkedList();
	// Ajout des valeurs 10-20-30-...-100 à la liste
	for (int i = 10; i <= 100; i += 10) {
		// création d'un maillon
		DoubleLinkedListElem* elem = NewDoubleLinkedListItem(i);
		// ajout du maillon à la liste
		insertItemAtDoubleLinkedListTail(MyList, elem);
	}
	// affichage des valeurs de la liste chainée
	DisplayDoubleList(MyList);
}


DoubleLinkedList* newDoubleLinkedList() {
	DoubleLinkedList* tmp;
	tmp = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	if (tmp != NULL) {
		tmp->head = NULL;
		tmp->tail = NULL;
		tmp->size = 0;
	}
	return tmp;
}

DoubleLinkedListElem* NewDoubleLinkedListItem(int value) {
	DoubleLinkedListElem* tmp;
	tmp = (DoubleLinkedListElem*)malloc(sizeof(DoubleLinkedListElem));
	if (tmp != NULL) {
		tmp->data = value;
		tmp->next = NULL;
		tmp->previous = NULL;
	}
	return(tmp);
}



int DisplayDoubleList(DoubleLinkedList* list) {
	if (list == NULL || list->head == NULL || list->tail == NULL) { return 0; }

	DoubleLinkedListElem* courant = list->head;
	while (courant != NULL) {
		printf("%d ", courant->data);
		courant = courant->next;
	}
	while (courant != NULL) {
		printf("%d ", courant->data);
		courant = courant->next;
	}
	return 1;
}


int RevDisplayDoubleList(DoubleLinkedList* list) {
	if (list == NULL)
		return 0;
	if (list->tail == NULL || list->head == NULL)
		return 0;
	DoubleLinkedListElem* tmp = list->tail;
	while (tmp != NULL) {
		printf("%d", tmp->data);
		tmp = tmp->previous;
	}
	return 1;
}


int insertItemAtDoubleLinkedListHead(DoubleLinkedList* list, DoubleLinkedListElem* newItem) {
	if (list == NULL)
		return 0;
	if (newItem == NULL || newItem->next != NULL || newItem->previous == NULL)
		return 0;

	if (list->tail == NULL) {
		list->tail = newItem;
		list->head = newItem;
		list->size = 1;
	}
	else {
		newItem->next = list->head;
		list->head->previous = newItem;
		list->head = newItem;
		list->size++;
	}
	return 1;
}



int insertItemAtDoubleLinkedListTail(DoubleLinkedList* list, DoubleLinkedListElem* newItem) {
	if (list == NULL)
		return 0;
	if (newItem == NULL || newItem->next != NULL || newItem->previous != NULL)
		return 0;

	if (list->tail == NULL) {
		list->tail = newItem;
		list->head = newItem;
		list->size = 1;
	}
	else {
		newItem->previous = list->tail;
		list->tail->next = newItem;
		list->tail = newItem;
		list->size++;
	}
	return 1;
}

int getDoubleLinkedListSize(DoubleLinkedList* list) {
	if (list != NULL) {
		return list->size;
	}
	return -1;
}

int insertItemAfterItem(DoubleLinkedList* list, DoubleLinkedListElem* item, DoubleLinkedListElem* newItem) {
	if (list == NULL)
		return 0;
	if (newItem == NULL || newItem->next != NULL || newItem->previous == NULL)
		return 0;
	if (item == NULL || item->next != NULL || item->previous == NULL)
		return 0;

	newItem->previous = item;
	newItem->next = item->next;
	item->next->previous = newItem;
	item->next = newItem;
	list->size++;
	return 1;
}


int insertItemBeforeItem(DoubleLinkedList* list, DoubleLinkedListElem* item, DoubleLinkedListElem* newItem) {
	insertItemAfterItem(list, item->previous, newItem);
}

int emptyDoubleLinkedList(DoubleLinkedList* list) {
	if (list == NULL) return 0;

	while (list->size != 0) {
		DoubleLinkedListElem* elem;
		elem = malloc(sizeof(*elem));
		elem = list->head;
		list->head = list->head->next;
		elem->next = NULL;
		elem->previous = NULL;
		free(elem);
		list->size--;
	}
	return 1;
}