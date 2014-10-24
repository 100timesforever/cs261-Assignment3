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
		
clean:
	rm cirListDeque.o
	rm testCirListDeque.o
