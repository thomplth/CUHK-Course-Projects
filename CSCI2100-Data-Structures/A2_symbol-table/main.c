#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symtab.h"

#define day 10

symtabADT symtabInput(FILE*); // read and input data from data.txt
void symtabPrint(char*, symtabEntryT); // output the data from symbol table
int sumOfList(symtabEntryT); // obtain the sum of integers in a list

int main() {
    /* open data file */
    FILE *fp;
    fp = fopen("data.txt", "r");
    
    if(fp == NULL) {
        perror("Error opening file data.txt");
        exit(EXIT_FAILURE);
    }
    
    /* process data */
    symtabADT table = symtabInput(fp);
    
    /* output data */
    forEachEntryDo(symtabPrint, table);
    
    fclose(fp);
    return 0;
}

symtabADT symtabInput(FILE *fp) {
    symtabADT table = EmptySymbolTable();
    listADT entry;
    char str[100]; // hold line of data
    char key[100];
    int value;
    
    // retrive data line n (key)
    while(fgets(str, 100, fp)) {
        sscanf(str, "%[^\n]s", key);
        // retrive data line 2n (value)
        fgets(str, 100, fp);
        sscanf(str, "%d", &value);
        
        // input data to symbol table "table"
        entry = Cons(value, EmptyList());
        Enter(table, key, entry);
    }
    return table;
}

void symtabPrint(char* key, symtabEntryT value) {
    if(strlen(key) > 13)
        printf("%s\t%d\n", key, sumOfList(value));
    else
        printf("%-13s%d\n", key, sumOfList(value));
}

int sumOfList(symtabEntryT list) {
    if(ListIsEmpty(Tail(list)))
        return Head(list);
    return Head(list) + sumOfList(Tail(list));
}
