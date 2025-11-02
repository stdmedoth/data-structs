CC=gcc

%.o: %.c
	$(CC) -g  -c -o $@ $< -I .

main: BinaryTree.o BinaryTreeNode.o main.o
	$(CC) -g -o $@ $^ 

clear:
	rm *.o main
