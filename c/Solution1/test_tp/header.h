

typedef struct DoubleLinkedListElem {
	int data;
	struct DoubleLinkedListElem* previous;
	struct DoubleLinkedListElem* next;
} DoubleLinkedListElem;


typedef struct DoubleLinkedList {
	DoubleLinkedListElem* head;
	int size;
	DoubleLinkedListElem* tail;
} DoubleLinkedList;


typedef struct Teleporteurs_Paire {
	int entree;
	int sortie;
}Teleporteurs_Paire;

// cr�ation d'une nouvelle liste cha�n�e bilat�re vide
// cette fonction renvoie un pointeur sur la nouvelle structure liste cha�n�e bilat�re vide
DoubleLinkedList* newDoubleLinkedList();
// instanciation (cr�ation) d'un �l�ment (maillon) � ins�rer dans une liste cha�n�e bilat�re
// avec stockage de la donn�e value dans l'�l�ment de liste
DoubleLinkedListElem* NewDoubleLinkedListItem(int value);
// affichage des �l�ments d'une liste cha�n�e bilat�re en commen�ant par la t�te
int DisplayDoubleList(DoubleLinkedList* list);


int insertItemAtDoubleLinkedListTail(DoubleLinkedList* list, DoubleLinkedListElem* newItem);

int recherche_loc_tp();

int deleteDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item);