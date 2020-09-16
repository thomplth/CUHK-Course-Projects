#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BinaryTree.h"

void printInOrder(BinaryTreeADT, BinaryTreeADT);

int main() {
    /* open data file */
    FILE *fp;
    fp = fopen("data.txt", "r");
    
    if(fp == NULL) {
        perror("Error opening file data.txt");
        exit(EXIT_FAILURE);
    }
    
    /* process data */
    int lineNo = 1;
    int temp;
    char key[10];
    char *token = NULL;
    char str[100];
    char *rest = str;
    
    // each loop represents one line
    while(fgets(str, 100, fp)) {
        printf("Tree %d\n", lineNo);
        
        // execute when line is not blank
        if(str[0] != '\n') {
            BinaryTreeADT tree = EmptyBinaryTree();
            
            // obtain and input all integers from the line
            token = strtok_r(str, " ", &rest);
            
            while(token != NULL) {
                // create new node with the value and insert it
                if(token[0] == '\n') break;
                
                // remove \n from token
                temp = atoi(token);
                sprintf(key, "%d", temp);
                
                TreeNodeADT node = NewTreeNode(key, 1);
                tree = InsertNode(tree, node);
                token = strtok_r(NULL, " ", &rest);
            }
            // perform in-order traversal
            printInOrder(tree, tree);
            
        } else printf("Empty Tree\n");
        
        printf("Done with Tree %d\n\n", lineNo++);
    }
    
    fclose(fp);
    return 0;
}

void printInOrder(BinaryTreeADT tree, BinaryTreeADT root) {
    if(!TreeIsEmpty(tree)) {
        // search for the leftmost node
        printInOrder(LeftSubtree(tree), root);
        if(parent(root, Root(tree)) == SpecialErrNode) {
            printf("Parent of %s does not exist\n", GetNodeKey(Root(tree)));
        } else {
            printf("Parent of %s is %s\n", GetNodeKey(Root(tree)), GetNodeKey(parent(root, Root(tree))));
        }
        // search for the rightmost node
        printInOrder(RightSubtree(tree), root);
    }
}
