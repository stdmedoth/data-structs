#include <stdio.h>
#include <AVLNode.h>

typedef struct AVLNode{
    int height;
    int value;
    AVLNode *left;
    AVLNode *right;
}AVLNode;

int max(int a, int b)
{
    return a > b ? a : b;
}

int avl_node_get_balancing_factor(AVLNode *avl_node)
{
    return (avl_node_get_height(avl_node->left), avl_node_get_height(avl_node->right));
}

AVLNode *avl_node_create(int value, int height, AVLNode *left, AVLNode *right)
{
    AVLNode *avl_node = malloc(sizeof(AVLNode));
    avl_node->height = height;
    avl_node->value = value;
    avl_node->right = right;
    avl_node->left = left;
    return avl_node;
}


AVLNode *avl_node_insert(AVLNode *avl_node, int value)
{
    if(!avl_node){
        return avl_node_create(value, 0, NULL, NULL);
    }
    if(value > avl_node->value){
        avl_node->right = avl_node_insert(avl_node->right, value);
    }else if(value < avl_node->value){
        avl_node->left = avl_node_insert(avl_node->left, value);
    }else{
        return avl_node;
    }

    avl_node->height = 1 + max(avl_node_get_height(avl_node->left), avl_node_get_height(avl_node->right));
    
    int fb = avl_node_get_balancing_factor(avl_node);
    
    // simple rotation

    // right-right
    if(fb > 1 && avl_node_get_balancing_factor(avl_node->right) > 0){
        avl_node = avl_node_rotation_to_left(avl_node);
    }

    // left-left
    else if(fb < 1 && avl_node_get_balancing_factor(avl_node->left) < 0){
        avl_node = avl_node_rotation_to_right(avl_node);
    }

    // double rotation
    // right left 
    else if(fb > 1 && avl_node_get_balancing_factor(avl_node->right) < 0){
        avl_node_rotation_to_right(avl_node->right);
        avl_node_rotation_to_left(avl_node);
    }
    
    // left right
    else if(fb < 1 && avl_node_get_balancing_factor(avl_node->left) < 0){
        avl_node_rotation_to_left(avl_node->left);
        avl_node_rotation_to_right(avl_node);
    }

    return avl_node;
    
}

AVLNode *avl_node_get_left(AVLNode *avl_node)
{
    return avl_node->left;
}

AVLNode *avl_node_get_right(AVLNode *avl_node)
{
    return avl_node->right;
}


int avl_node_get_height(AVLNode *avl_node)
{
    if(!avl_node) return -1;

    return avl_node->height;
}

int avl_node_get_value(AVLNode *avl_node)
{
    return avl_node->value;
}


void avl_node_set_left(AVLNode *avl_node, AVLNode *left)
{
    avl_node->left = left;
}

void avl_node_set_right(AVLNode *avl_node, AVLNode *right)
{
    avl_node->right = right;
}


void avl_node_set_height(AVLNode *avl_node, int height)
{
    avl_node->height = height;
}

void avl_node_set_value(AVLNode *avl_node, int value)
{
    avl_node->value = value;
}

