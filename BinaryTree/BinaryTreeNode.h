typedef struct BinaryTreeNode BinaryTreeNode;


BinaryTreeNode *bintree_node_create();


void bintree_node_set_left(BinaryTreeNode *node, BinaryTreeNode *left);

void bintree_node_set_right(BinaryTreeNode *node, BinaryTreeNode *right);

BinaryTreeNode * bintree_node_get_left(BinaryTreeNode *node);

BinaryTreeNode * bintree_node_get_right(BinaryTreeNode *node);

void bintree_node_set_value(BinaryTreeNode *node, int value);

int bintree_node_get_value(BinaryTreeNode *node);

BinaryTreeNode *bintree_node_higher_node(BinaryTreeNode *node, BinaryTreeNode **parent);

void bintree_node_free(BinaryTreeNode *node);