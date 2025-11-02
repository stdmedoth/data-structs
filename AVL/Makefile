CC=gcc

%.o: %.c 
	$(CC) -c -o $@ $< -I .


main: AVL.o AVLNode.o main.o
	$(CC) -o $@ $^


clear:
	rm *.o main