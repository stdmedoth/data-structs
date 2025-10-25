#include <BinaryTreeNode.h>

#ifndef  _BINARY_TREE
#define  _BINARY_TREE


typedef struct BinaryTree BinaryTree;

BinaryTree *bintree_create();

BinaryTreeNode *bintree_get_root(BinaryTree *bintree);

void bintree_set_root(BinaryTree *bintree, BinaryTreeNode *root);

void bintree_insert(BinaryTree *bintree, int value);

void bintree_inorder(BinaryTreeNode *node);

void bintree_preorder(BinaryTreeNode *node);

void bintree_posorder(BinaryTreeNode *node);

int bintree_remove(BinaryTree *bintree, int value);



#endif