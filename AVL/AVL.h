#ifndef _H_AVL
#define _H_AVL

typedef struct AVL AVL;

AVL *avl_create();

void avl_insert(AVL *avl, int value);

void avl_search(AVL *avl, int value);

void avl_remove(AVL *avl, int value);

#endif