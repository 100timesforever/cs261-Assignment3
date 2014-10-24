default: prog

linkedList.o: linkedList.c 
	gcc -Wall -g -std=c99 -c linkedList.c

testLinkedList.o: testLinkedList.c
	gcc -Wall -g -std=c99 -c testLinkedList.c

linked: linkedList.o testLinkedList.o
	gcc -Wall -g -std=c99 -o linked testLinkedList.o linkedList.o

cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c	

testCirListDeque.o: cirListDeque.h testCirListDeque.c
	gcc -Wall -g -std=c99 -c testCirListDeque.c

prog: cirListDeque.o testCirListDeque.o
	gcc -Wall -g -std=c99 -o prog cirListDeque.o testCirListDeque.o

linkedListMain.o:
	gcc -Wall -g -std=c99 -c linkedListMain.c

massifLinked: linkedListMain.o linkedList.o
	gcc -Wall -g -std=c99 -o massifLinked linkedListMain.o linkedList.o

dynamicArray.o: dynamicArray.c
	gcc -Wall -g -std=c99 -c dynamicArray.c

dynamicArrayMain.o: dynamicArrayMain.c
	gcc -Wall -g -std=c99 -c dynamicArrayMain.c

massifDynamic: dynamicArray.o dynamicArrayMain.o
	gcc -Wall -g -std=c99 -o massifDynamic dynamicArray.o dynamicArrayMain.o
clean:
	rm cirListDeque.o
	rm testCirListDeque.o
