#include <stdio.h>
#include <BinaryTreeNode.h>
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

void bintree_node_free(BinaryTreeNode *node)
{
    free(node);
}

BinaryTreeNode *bintree_node_higher_node(BinaryTreeNode *node, BinaryTreeNode **parent)
{
    BinaryTreeNode *current = node;
    BinaryTreeNode *right;
    while(current){
        right = bintree_node_get_right(current);
        if(!right) break;
        *parent = current;
        current = right;
        
    }

    return current;
    

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

