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


void bintree_remove(BinaryTree *bintree, int value)
{
    BinaryTreeNode *root = bintree_get_root(bintree);
    
    if(!root) return ;

    BinaryTreeNode *current = root;
    BinaryTreeNode *parent = root;
    int side_child = -1; // 0 left, 1 right

    while(1){
        BinaryTreeNode *right = bintree_node_get_right(current);
        BinaryTreeNode *left = bintree_node_get_left(current);
        if(value > bintree_node_get_value(current)){
            parent = current;
            if(right) current = right;
            side_child = 1;

        }else if(bintree_node_get_value(current) > value){
            parent = current;
            if(left) current = left;
            side_child = 0;
        }else{
            // 3 casos
            // caso 1 : Nó removido não tem filhos
            // Apenas remove o nó e altera o a relação do pai para o filho apontando para NULL
            if(!left && !right){
                if(side_child == 0){
                    bintree_node_set_left(parent, NULL);
                }
                if(side_child == 1){
                    bintree_node_set_right(parent, NULL);
                }
                bintree_node_free(current);
                return ;
            }

            // caso 2 : Nó removido tem apenas um filho a direita/esquerda
            // Remove o nó e coloca o filho do nó no lugar do pai removido
            if(!left && right){
                if(side_child == 0){
                    bintree_node_set_left(parent, right);
                }
                if(side_child == 1){
                    bintree_node_set_right(parent, right);
                }
                bintree_node_free(current);
                return ;
            }
            if(left && !right){
                if(side_child == 0){
                    bintree_node_set_left(parent, left);
                }
                if(side_child == 1){
                    bintree_node_set_right(parent, left);
                }
                bintree_node_free(current);
                return ;
            }

            // caso 3 : Nó removido tem dois filhos
            // Remove o nó e coloca o filho do nó no lugar do pai removido
            if(left && right){                
                BinaryTreeNode *hight_node_parent = current;

                BinaryTreeNode *hight_node = bintree_node_higher_node(left, &hight_node_parent); // Pega a maior chave da subarvore da esquerda
                BinaryTreeNode *hight_node_left_child = bintree_node_get_left(hight_node);

                int value = bintree_node_get_value(hight_node); 
                bintree_node_set_value(current, value); // Atualiza o valor do node a ser removido com o valor encontrado anteriormente
                if(hight_node_left_child == current){ 
                    // Se o nó a esquerda não tem filhos a direita, então o maior valor a esquerda é o proprio filho a esquerda... 
                    // nesse caso, o filho a esquerda vira filho do novo pai
                    bintree_node_set_left(hight_node_parent, hight_node_left_child); 
                }else{
                    // Se o nó a esquerda tem filhos a direita, então pega o maior nó dele e coloca os filhos a esquerda do maior no a esquerda como filho do pai do maior nó a esquerda
                    bintree_node_set_right(hight_node_parent, hight_node_left_child); 
                }
                bintree_node_free(hight_node);
                return ;
            }

        }
    }
}
