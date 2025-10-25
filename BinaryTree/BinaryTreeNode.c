#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode{
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
}BinaryTreeNode;


BinaryTreeNode *bintree_node_create()
{
    BinaryTreeNode *node  = malloc(sizeof(BinaryTreeNode));
    node->left = NULL;
    node->right = NULL;

    return node;
}

void bintree_node_set_left(BinaryTreeNode *node, BinaryTreeNode *left)
{
    node->left = left;
}

void bintree_node_set_right(BinaryTreeNode *node, BinaryTreeNode *right)
{
    node->right = right;
}

BinaryTreeNode * bintree_node_get_left(BinaryTreeNode *node)
{
    return node->left;
}

BinaryTreeNode * bintree_node_get_right(BinaryTreeNode *node)
{
    return node->right;
}

void bintree_node_set_value(BinaryTreeNode *node, int value)
{
    node->value = value;
}

int bintree_node_get_value(BinaryTreeNode *node)
{
    return node->value;
}

