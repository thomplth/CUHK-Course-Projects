/* File: BinaryTree.h */
#include <stdlib.h>
#include <stdbool.h>
typedef struct BinaryTreeCDT *BinaryTreeADT;
typedef struct TreeNodeCDT *TreeNodeADT;
#define SpecialErrNode (TreeNodeADT) NULL

BinaryTreeADT NonemptyBinaryTree(TreeNodeADT, BinaryTreeADT, BinaryTreeADT);
BinaryTreeADT EmptyBinaryTree(void);
BinaryTreeADT LeftSubtree(BinaryTreeADT);
BinaryTreeADT RightSubtree(BinaryTreeADT);
bool TreeIsEmpty(BinaryTreeADT);
TreeNodeADT Root(BinaryTreeADT);
TreeNodeADT NewTreeNode(char*, int);
int GetNodeData(TreeNodeADT);
char *GetNodeKey(TreeNodeADT);

TreeNodeADT FindNode(BinaryTreeADT, char);
BinaryTreeADT InsertNode(BinaryTreeADT, TreeNodeADT);
BinaryTreeADT DeleteNode(BinaryTreeADT, TreeNodeADT);

TreeNodeADT parent(BinaryTreeADT, TreeNodeADT);\
