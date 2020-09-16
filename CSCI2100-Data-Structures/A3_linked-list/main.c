#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

// question 7
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
    int listLen = 0;
    
    char *token;
    char str[100];
    char *rest = str;
    int value[100];
    
    // each loop represents one line
    while(fgets(str, 100, fp)) {
        printf("Line %d\n", lineNo);
        
        // execute when line is not blank
        if(str[0] != '\n') {
            // obtain all integers from the line
            token = strtok_r(str, " ", &rest);
            while(token != NULL) {
                value[listLen++] = atoi(token);
                token = strtok_r(NULL, " ", &rest);
            }
        }
        
        // input the data into a new list
        listADT list = ListOf2(listLen, value);
        PrintList(list);
        
        // sort the list
        list = quicksortList(list);
        PrintList(list);
        
        printf("Done with Line %d\n\n", lineNo++);
        listLen = 0;
    }
    
    fclose(fp);
    return 0;
}
