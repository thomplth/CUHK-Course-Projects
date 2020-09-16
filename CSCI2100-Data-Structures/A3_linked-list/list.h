/*
 * File: list.h
 */
typedef struct listCDT *listADT;

typedef int listElementT;

listADT EmptyList(void);
listADT Cons(listElementT, listADT);
listElementT Head(listADT);
listADT Tail(listADT);
int ListIsEmpty(listADT);

/* Added functions */
listADT quicksortList(listADT);
listADT SmallerList(listADT);
listADT LargerOrEqList(listADT);
listADT ListOf(int, ...);
listADT ListOf2(int, int []);
void PrintList(listADT);

listADT appendList(listADT, listADT);
