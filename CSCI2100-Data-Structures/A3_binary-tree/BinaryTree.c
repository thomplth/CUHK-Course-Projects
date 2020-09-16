//
//  BinaryTree.c
//  Tree
//
//  Created by ThompsonLam on 13/4/2020.
//  Copyright © 2020 ThompsonLam. All rights reserved.
//

#include "BinaryTree.h"
#include <stdio.h>
#include <string.h>

struct BinaryTreeCDT {
    TreeNodeADT rt;
    BinaryTreeADT lst;
    BinaryTreeADT rst;
};

struct TreeNodeCDT {
    char* key;
    int nodeData;
};

BinaryTreeADT NonemptyBinaryTree(TreeNodeADT N, BinaryTreeADT L, BinaryTreeADT R) {
    BinaryTreeADT t = (BinaryTreeADT) malloc(sizeof(*t));
    t->rt = N;
    t->lst = L;
    t->rst = R;
    return t;
}

BinaryTreeADT EmptyBinaryTree() {
    return (BinaryTreeADT) NULL;
}

BinaryTreeADT LeftSubtree(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->lst;
}

BinaryTreeADT RightSubtree(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->rst;
}

bool TreeIsEmpty(BinaryTreeADT t) {
    return t == (BinaryTreeADT) NULL;
}

TreeNodeADT Root(BinaryTreeADT t) {
    if (TreeIsEmpty(t))  {
           printf("root?\n");
           exit(EXIT_FAILURE);
       }
    return t->rt;
}

TreeNodeADT NewTreeNode(char* k, int d) {
    TreeNodeADT N = (TreeNodeADT) malloc(sizeof(*N));
    N->key = (char*) malloc(sizeof(char)*(strlen(k)+1));
    strcpy(N->key, k); N->nodeData = d;
    return(N);
}

int GetNodeData(TreeNodeADT N) {
    return N->nodeData;
}

char *GetNodeKey(TreeNodeADT N) {
    char *k;
    if (N==(TreeNodeADT)NULL) exit(EXIT_FAILURE);
    k = (char*) malloc(sizeof(char)*(strlen(N->key)+1));
    strcpy(k, N->key);
    return k;
}

TreeNodeADT parent(BinaryTreeADT tree, TreeNodeADT node) {
    if(TreeIsEmpty(tree)) exit(EXIT_FAILURE);
    
    // node has no parent
    if(strcmp(GetNodeKey(Root(tree)),GetNodeKey(node)) == 0)
        return SpecialErrNode;
    
    // search for the node from the tree
    // node is smaller than current root
    if(strcmp(GetNodeKey(Root(tree)),GetNodeKey(node)) > 0) {
        if(strcmp(GetNodeKey(Root(LeftSubtree(tree))),GetNodeKey(node)) == 0)
           return Root(tree);
        return parent(LeftSubtree(tree), node);
    }
    // node is larger than current root
    else {
        if(strcmp(GetNodeKey(Root(RightSubtree(tree))),GetNodeKey(node)) == 0)
            return Root(tree);
        return parent(RightSubtree(tree), node);
    }
}

BinaryTreeADT InsertNode(BinaryTreeADT t, TreeNodeADT n) {
    if (TreeIsEmpty(t))
        return NonemptyBinaryTree(n, EmptyBinaryTree(), EmptyBinaryTree());
    else {
        int sign = strcmp(GetNodeKey(n), GetNodeKey(Root(t)));
        if (sign == 0) return NonemptyBinaryTree(n, LeftSubtree(t), RightSubtree(t));
        if (sign < 0) return NonemptyBinaryTree(Root(t), InsertNode(LeftSubtree(t),n), RightSubtree(t));
        return NonemptyBinaryTree(Root(t),LeftSubtree(t), InsertNode(RightSubtree(t), n));
    }
}

TreeNodeADT FindMinNode(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) return SpecialErrNode;
    if (TreeIsEmpty(LeftSubtree(t))) return Root(t);
    return FindMinNode(LeftSubtree(t));
}

BinaryTreeADT DeleteNode(BinaryTreeADT t, TreeNodeADT n) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    int sign = strcmp(GetNodeKey(n), GetNodeKey(Root(t)));
    if (sign<0) return NonemptyBinaryTree(Root(t), DeleteNode(LeftSubtree(t), n), RightSubtree(t));
    if (sign>0) return NonemptyBinaryTree(Root(t), LeftSubtree(t), DeleteNode(RightSubtree(t), n));
    if (!TreeIsEmpty(LeftSubtree(t)) && !TreeIsEmpty(RightSubtree(t))) {
        TreeNodeADT M = FindMinNode(RightSubtree(t));
        return NonemptyBinaryTree(M, LeftSubtree(t), DeleteNode(RightSubtree(t), M));
    }
    if (TreeIsEmpty(RightSubtree(t)))
        return LeftSubtree(t);
    else
        return RightSubtree(t);
}
