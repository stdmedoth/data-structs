CC=gcc

%.o: %.c $(INCLUDES)
	$(CC) -g  -c -o $@ $< -I .

main: BinaryTree.o BinaryTreeNode.o main.o
	$(CC) -g -o $@ $^ $(CFLAGS)

clear:
	rm *.o main
