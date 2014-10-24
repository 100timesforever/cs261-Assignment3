#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
  /* FIXME: you must write this */
	if(lst != NULL) {
		lst->size = 0;
		lst->firstLink = NULL;
		lst->lastLink = NULL;
	}
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	struct DLink *new = malloc(sizeof(struct DLink));
	/* FIXME: you must write this */
	if(lst != NULL) {
		if(l != NULL) {
			new->value = v;
			new->next = l;
			new->prev = l->prev;
			if(l->prev != NULL){
				l->prev->next = new;
			}
			else{
				lst->firstLink = new;
			}
			l->prev = new;
			lst->size++;
			//printf("size in _addLinkBefore: %d\n", lst->size);
		}
	}
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* FIXME: you must write this */
	if(lst != NULL) {
		if(l != NULL) {
			//assert(lst->size > 0);
			if(l->prev != NULL && l->next != NULL) {
				l->prev->next = l->next;
				l->next->prev = l->prev;
			}
			else if(l->prev == NULL && l->next != NULL) {
				lst->firstLink = l->next;
				l->next->prev = NULL;
			}
			else if(l->prev != NULL && l->next == NULL) {
				l->prev->next = NULL;
				lst->lastLink = l->prev;
			}
			else {
				lst->firstLink = NULL;
				lst->lastLink = NULL;
			}
			free(l);
			lst->size -= 1;
		}
	}
	
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/
int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */
	if(lst != NULL) {
		if(lst->lastLink == NULL && lst->firstLink == NULL) {
			return(1);
		}
		else
			return(0);
	}
	return 1; //In the case where the list is equal to NULL, return 1.
}

/* De-allocate all links of the list

	param: 	lst		pointer to the linked list
	pre:	none
	post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst)
{
	while(!isEmptyList(lst)) {
		//printf("In the while loop\n");
		//printf("lst->size: %d\n", lst->size);
		/* remove the link right after the first sentinel */
		_removeLink(lst, lst->firstLink);//->next);
	}		
	/* remove the first and last sentinels */
	//free(lst->firstLink);
	//free(lst->lastLink);	
}

/* 	Deallocate all the links and the linked list itself. 

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteLinkedList(struct linkedList *lst)
{
	assert (lst != NULL);
	freeLinkedList(lst);
	free(lst);
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{	struct DLink* itr;
	itr = lst->firstLink;
	TYPE v;
	/* FIXME: you must write this */
	int i;
	for(i=0; i<lst->size; i++) {
		v = itr->value;
		printf("%d\n", v);
		//printf("i:%d   size:%d\n", i, lst->size);
		if((lst->size - i) > 0) {
			//printf("iterating iter\n");
			itr = itr->next;
		}
		else{
			return;
		}
	}
//	printf("Hopefully exiting _printList\n");
}

/* ************************************************************************
	Deque Interface Functions
************************************************************************ */

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e)
{
	struct DLink *new = malloc(sizeof(struct DLink));

	/* FIXME: you must write this */
	if(lst!=NULL) {
		if(isEmptyList(lst)){
			new->value = e;
			lst->firstLink = new;
			lst->lastLink = new;
			new->next = NULL;
			new->prev = NULL;
			lst->size++;
		}	
		else{
			_addLinkBefore(lst, lst->firstLink, e);
		}
	}
//	printf("size in ADDFRONTLIST: %d\n", lst->size);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e) {
 
	struct DLink *new = malloc(sizeof(struct DLink)); 
	
	if(lst!=NULL) {
		if(isEmptyList(lst)){
			new->value = e;
			lst->firstLink = new;
			lst->lastLink = new;
			new->next = NULL;
			new->prev = NULL;
		}	
		else{
			new->value = e;
			new->prev = lst->lastLink;
			lst->lastLink = new;
			new->next = NULL;
			new->prev->next = new;
		}
	lst->size += 1;
	//printf("LIST SIZE IN ADD BACK: %d\n", lst->size);
	}
	
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/
TYPE frontList (struct linkedList *lst) {
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	if(lst != NULL){
		if(!isEmptyList(lst)){
			return lst->firstLink->value;
		}
	}	
	return(1);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/
TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	/*temporary return value...you may need to change this */
	if(lst != NULL){
		if(!isEmptyList(lst)){
			return lst->lastLink->value;
		}
	}
	return(1);
}



/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst) {
   	/* FIXME: you must write this */
	if(lst != NULL){
		if(!isEmptyList(lst)){
			_removeLink(lst, lst->firstLink);
		}
	}
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/
void removeBackList(struct linkedList *lst)
{	
	/* FIXME: you must write this */
	if(lst != NULL){
		if(!isEmptyList(lst)){
			_removeLink(lst, lst->lastLink);
		}
	}
	
}


/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	struct DLink *new = malloc(sizeof(struct DLink));
	/* FIXME: you must write this */
	if(lst != NULL) {
		if(isEmptyList(lst)){
			lst->firstLink = new;
			lst->lastLink = new;
			new->next = NULL;
			new->prev = NULL;
			new->value = v;
			lst->size += 1;
		}	
		else{
			_addLinkBefore(lst, lst->firstLink, v);
		}
	
	}

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	struct DLink * itr = lst->firstLink;
	int i;
	/* FIXME: you must write this */
	if(lst != NULL) {
		if(lst->size > 0) {
			for(i=0; i < lst->size - 1; i++) {
				if(itr->value == e) {
					return(1);
				}
				itr = itr->next;
			}
		}
	}
	return(0);//once agian, if list is NULl, it can't be contained in it. 
			  //(This part is mainly to make gcc happy)
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	struct DLink * itr = lst->firstLink;
	/* FIXME: you must write this */
	if(lst != NULL) {
		if(lst->size > 0) {
			if(containsList(lst, e)) {
				if(itr->value == e) {
					_removeLink(lst, itr);
				}
				itr = itr->next;
			}
		}
	}
}
