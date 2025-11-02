#include <stdio.h>
#include <AVL.h>
#include <AVLNode.h>


typedef struct AVL{
    AVLNode *root;
}AVL;

AVL *avl_create()
{
    
}

AVLNode *avl_get_root(AVL *avl)
{
    return avl->root;
}

void avl_insert(AVL *avl, int value)
{
    AVLNode *root = avl_get_root(avl);
    AVLNode *right = NULL, *left = NULL;

    avl_node_insert(root, value);
}

void avl_search(AVL *avl, int value)
{
    
}

void avl_remove(AVL *avl, int value)
{
    
}


