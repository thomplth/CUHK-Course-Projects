/*
 * File: DisjSet.h
 */
typedef struct DisjSetCDT *DisjSetADT;

DisjSetADT NewDisjointSet(void);
void SetUnion(DisjSetADT, int, int);
int Find(int, DisjSetADT);
