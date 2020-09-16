/*
 * File: symtab.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "symtab.h"

typedef struct cellT {
    char *key;
    symtabEntryT value;
} cellT;

struct symtabCDT {
    cellT **bucket; // An array of cellT*, which can be extended.
    int nBuckets; // Current number of buckets (size of the bucket array)
    int nEntries; // Current number of entries.
};

int Hash(char *s, int nBuckets) { // DO NOT MODIFY.
    unsigned long hashcode = 0;
    for (int i=0; s[i]!='\0'; i++) hashcode = (hashcode<<5) + s[i];
    return (int) (hashcode % nBuckets);
}

symtabADT EmptySymbolTable() { // DO NOT MODIFY.
    symtabADT T1 = (symtabADT) malloc(sizeof(*T1));
    T1->bucket = (cellT*) malloc(5*sizeof(cellT*)); // Initial size is 5.
    T1->nBuckets = 5; T1->nEntries = 0;
    for (int i = 0; i < T1->nBuckets; i++) T1->bucket[i]=(cellT*)NULL;
    return T1;
}

void Enter(symtabADT T1, char* K1, symtabEntryT V1) {
    // check if table is full
    /* rehashing */
    if(T1->nBuckets == T1->nEntries) {
        // make a copy of T1
        symtabADT T2 = (symtabADT) malloc(sizeof(*T1));
        T2->bucket = (cellT*) malloc((T1->nBuckets) * sizeof(cellT*));
        T2->nBuckets = T1->nBuckets;
        T2->nEntries = 0;
        for (int i = 0; i < T2->nBuckets; i++)
        T2->bucket[i] = (cellT*)NULL;
        
        for (int i = 0; i < T1->nBuckets; i++)
            if (T1->bucket[i] != NULL)
                Enter(T2, T1->bucket[i]->key, T1->bucket[i]->value);
        
        // extend the bucket size of T1 by 7
        T1->nBuckets += 7;
        T1->bucket = (cellT*) realloc(T1->bucket, T1->nBuckets * sizeof(cellT*));
        for(int i = 0; i < T1->nBuckets; i++)
            T1->bucket[i] = (cellT*) NULL;
        
        // mapping element in T2 back to T1
        for(int i = 0; i < T2->nBuckets; i++)
            if (T2->bucket[i] != NULL)
                Enter(T1, T2->bucket[i]->key, T2->bucket[i]->value);
    }
    /* end of rehash */

    /* entry */
    // obtain hash code from inputed data
    int hashCode = Hash(K1, T1->nBuckets);
    cellT *cp = T1->bucket[hashCode];
    
    // check cirsumstances
    // 1) no entry with same hash code
    // 2) different entry with same hash code
    // 3) same entry with same hash code
    if(cp == NULL) {
        // 1) create new entry when no collision occur
        cp = (cellT*)malloc(sizeof(*cp));
        cp->key = (char*)malloc(sizeof(char)*(strlen(K1)+1));
        strcpy(cp->key, K1);
        cp->value = V1;
        T1->nEntries++; // new entry is created
    } else if(strcmp(T1->bucket[hashCode]->key, K1) != 0) {
        // 2) use linear probing when collison
        do hashCode = (hashCode + 1) % T1->nBuckets; while(T1->bucket[hashCode] != NULL);
        cp = (cellT*)malloc(sizeof(*cp));
        cp->key = (char*)malloc(sizeof(char)*(strlen(K1)+1));
        strcpy(cp->key, K1);
        cp->value = V1;
        T1->nEntries++; // new entry is created
    } else {
        // 3) append the new value to corresponding cell if entry exist
        cp->value = Cons(Head(V1), T1->bucket[hashCode]->value);
    }
    
    // assign the data to corresponing bucket
    T1->bucket[hashCode] = cp;
    /* end of entry */
}

symtabEntryT Lookup(symtabADT T1, char* K1) {
    // obtain hash code from inputed data
    int hashCode = Hash(K1, T1->nBuckets);
    symtabEntryT L1 = EmptyList();
    
    // search with linear probing approach
    for (int i = 0; i < T1->nBuckets; i++) {
        // find corresponding list
        if(T1->bucket[(hashCode + i) % T1->nBuckets] != NULL) {
            if(strcmp(T1->bucket[(hashCode + i) % T1->nBuckets]->key, K1) == 0) {
                L1 = T1->bucket[hashCode]->value;
                break;
            }
        }
    }
    return L1;
}

void forEachEntryDo(symtabFnT f, symtabADT T1) { // DO NOT MODIFY.
    for (int i = 0; i < T1->nBuckets; i++)
        if (T1->bucket[i] != NULL)
            f(T1->bucket[i]->key, T1->bucket[i]->value);
}

void printList(listADT L) { // DO NOT MODIFY.
    if (ListIsEmpty(L))
        printf("nil");
    else {
        printf("%d:", Head(L));
        printList(Tail(L));
    }
}

void ShowAll(symtabADT T1){ // DO NOT MODIFY.
    for (int i = 0; i < T1->nBuckets; i++)
        if (T1->bucket[i] != NULL) {
            printf("Bucket %d\t Key:%s\t Value ", i, T1->bucket[i]->key);
            printList(T1->bucket[i]->value);
            printf("\n");
        }
}
