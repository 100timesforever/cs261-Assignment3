#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        int temp;

	/* Test your linked list in here! */

	printf("Testing Deque Implementation\n");
	struct linkedList * deque = createLinkedList();
	printf("Linked list deque created\n");
	addFrontList(deque, 3);
	printf("Added first element\n");
	addFrontList(deque, 8);
	_printList(deque);
	printf("Added second element\n");
	addBackList(deque, 2);
	printf("Added third element\n");
	temp = frontList(deque);
	printf("The front of the list is %d, it should be 8\n", temp);
	_printList(deque);
	printf("Printed the list.\n");
	removeFrontList(deque);
	printf("removed front\n");
	removeBackList(deque);
	printf("removed back\n");
	_printList(deque);
	printf("printed the list again.");
	deleteLinkedList(deque);
	printf("deleted and freed deque\n");

	printf("Testing Bag Implementation\n");
	struct linkedList * bag = createLinkedList();
	printf("linked list created\n");
	addList(bag, 4);
	printf("added first link");
	addList(bag, 6);
	printf("added second link");
	temp = containsList(bag, 6);
	printf("checked if list contains 6. temp should be 1, is %d\n", temp);
	temp = containsList(bag, 9);
	printf("checked if list contains 9. temp should be 0, is %d\n", temp);
	_printList(bag);
	printf("current list\n");
	removeList(bag, 6);
	printf("removed 6\n");
	_printList(bag);

	return 0;
}


