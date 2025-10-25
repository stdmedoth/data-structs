#include <stdio.h>
#include <stdlib.h>
#include <BinaryTree.h>
#include <BinaryTreeNode.h>


typedef struct BinaryTree{
    BinaryTreeNode *root;

}BinaryTree;


BinaryTree *bintree_create()
{
    BinaryTree *bintree = malloc(sizeof(BinaryTree));

    bintree->root = NULL;
    
    return bintree;
}

void bintree_set_root(BinaryTree *bintree, BinaryTreeNode *root)
{
    bintree->root = root;
}

BinaryTreeNode *bintree_get_root(BinaryTree *bintree)
{
    return bintree->root;
}

void bintree_insert(BinaryTree *bintree, int value)
{
    
    BinaryTreeNode *root = bintree_get_root(bintree);
    if(!root){
        BinaryTreeNode *root = bintree_node_create();
        bintree_set_root(bintree, root);
        bintree_node_set_value(root, value);
        return;
    }


    BinaryTreeNode *current = root;

    while(1){
        if(value > bintree_node_get_value(current)){
            BinaryTreeNode *has_right = bintree_node_get_right(current);
            if(!has_right){
                BinaryTreeNode *right = bintree_node_create();
                bintree_node_set_right(current, right);
                bintree_node_set_value(right, value);
                return ;
            }
            current = has_right;
        }else if(bintree_node_get_value(current) > value){
            BinaryTreeNode *has_left = bintree_node_get_left(current);
            if(!has_left){
                BinaryTreeNode *left = bintree_node_create();
                bintree_node_set_left(current, left);
                bintree_node_set_value(left, value);
                return ;
            }
            current = has_left;
        }else{
            return ;
        }
    

    }
}


void bintree_inorder(BinaryTreeNode *node)
{
    if(node){
        BinaryTreeNode *left = bintree_node_get_left(node);
        BinaryTreeNode *right = bintree_node_get_right(node);
        
        
        bintree_inorder(left);
        printf("%d ", bintree_node_get_value(node));
        bintree_inorder(right);
    }
}


void bintree_preorder(BinaryTreeNode *node)
{
    if(node){
        BinaryTreeNode *left = bintree_node_get_left(node);
        BinaryTreeNode *right = bintree_node_get_right(node);
        
        
        printf("%d ", bintree_node_get_value(node));
        bintree_preorder(left);
        bintree_preorder(right);
    }
}

void bintree_posorder(BinaryTreeNode *node)
{
    if(node){
        BinaryTreeNode *left = bintree_node_get_left(node);
        BinaryTreeNode *right = bintree_node_get_right(node);
        
        
        bintree_posorder(left);
        bintree_posorder(right);
        printf("%d ", bintree_node_get_value(node));
    }
}



int bintree_remove(BinaryTree *bintree, int value)
{
    
}
