/*
 * File: list.c
 */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "list.h"

typedef struct listCDT *listADT;

struct listCDT {
    listElementT h;
    listADT t;
};

listADT EmptyList() {
    return((listADT)NULL);
}

listADT Cons(listElementT h1, listADT t1) {
    listADT list = (listADT) malloc(sizeof(*list));
    list->h = h1;
    list->t = t1;
    return (list);
}

listElementT Head(listADT list) {
    if (ListIsEmpty(list))
        exit(EXIT_FAILURE);
    return (list->h);
}

listADT Tail(listADT list) {
    if (ListIsEmpty(list))
        exit(EXIT_FAILURE);
    return (list->t);
}

int ListIsEmpty(listADT list) {
    return (list == NULL);
}

// question 3
listADT appendList(listADT L1, listADT L2) {
    if(ListIsEmpty(L1)) return L2;
    if(ListIsEmpty(L2)) return L1;
    if(ListIsEmpty(Tail(L1))) return Cons(Head(L1), L2);
    
    // recursive function to add elements in L1 to L2 one by one
    return Cons(Head(L1), appendList(Tail(L1), L2));
}

listADT quicksortList(listADT list) {
    if(ListIsEmpty(list)) return EmptyList();
    if(ListIsEmpty(Tail(list))) return list;
    
    // recursive function to sort the list in two sides
    // combine the result using append function
    return appendList(quicksortList(SmallerList(list)), quicksortList(LargerOrEqList(list)));
}

listADT SmallerList(listADT list) {
    listADT nList = EmptyList();
    int pivot = Head(list);
    
    // search for elements smaller than pivot
    while(!ListIsEmpty(list)) {
        if(pivot > Head(list))
            nList = Cons(Head(list), nList);
        list = Tail(list);
    }
    
    return nList;
}

listADT LargerOrEqList(listADT list) {
    listADT nList = EmptyList();
    int pivot = Head(list);
    
    // search for elements larger or equal to pivot
    while(!ListIsEmpty(list)) {
        if(pivot <= Head(list))
            nList = Cons(Head(list), nList);
        list = Tail(list);
    }
    
    return nList;
}

// question 4
listADT ListOf(int length, ...) {
    if(length < 0) exit(EXIT_FAILURE);
    if(length == 0) return EmptyList();
    
    va_list args;
    listADT list = EmptyList();
    int value[length];
    
    va_start(args, length);
    
    // save all arguments in new array
    for(int i = 0; i < length; i++)
        value[i] = va_arg(args, int);
    
    // construct new list with the array in reverse order
    while(length > 0)
        list = Cons(value[--length], list);
    
    va_end(args);
    return list;
}

// question 5
listADT ListOf2(int length, int arr[]) {
    if(length < 0) exit(EXIT_FAILURE);
    if(length == 0) return EmptyList();
    
    listADT list = EmptyList();
    
    // adding variables to new list from the end of array
    while(length > 0)
        list = Cons(arr[--length], list);
    
    return list;
}

// question 6
void PrintList(listADT list) {
    printf("[");
    while(!ListIsEmpty(list)) {
        if(ListIsEmpty(Tail(list)))
            printf("%d", Head(list));
        else
            printf("%d, ", Head(list));
        list = Tail(list);
    }
    printf("]\n");
}
