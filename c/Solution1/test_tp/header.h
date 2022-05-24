

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

// création d'une nouvelle liste chaînée bilatère vide
// cette fonction renvoie un pointeur sur la nouvelle structure liste chaînée bilatère vide
DoubleLinkedList* newDoubleLinkedList();
// instanciation (création) d'un élément (maillon) à insérer dans une liste chaînée bilatère
// avec stockage de la donnée value dans l'élément de liste
DoubleLinkedListElem* NewDoubleLinkedListItem(int value);
// affichage des éléments d'une liste chaînée bilatère en commençant par la tête
int DisplayDoubleList(DoubleLinkedList* list);


int insertItemAtDoubleLinkedListTail(DoubleLinkedList* list, DoubleLinkedListElem* newItem);

int recherche_loc_tp();

int deleteDoubleLinkedListItem(DoubleLinkedList* list, DoubleLinkedListElem* item);