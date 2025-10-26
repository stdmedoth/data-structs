#include <stdio.h>
#include <BinaryTree.h>


int main()
{
    int numbers[20] = {
        7, 42, 19, 88, 3, 
        51, 99, 12, 64, 30,
        22, 5, 73, 49, 11,
        8, 92, 37, 60, 25
    };

    BinaryTree *bintree = bintree_create();
    for(int i=0; i<20; i++){
        bintree_insert(bintree, numbers[i]);
    }

    bintree_remove(bintree, 30);

    bintree_inorder(bintree_get_root(bintree));

}