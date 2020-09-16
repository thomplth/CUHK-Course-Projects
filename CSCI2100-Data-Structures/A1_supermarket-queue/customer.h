/*
Customer.h
*/
#include <stdio.h>

typedef struct customer *customerT;

customerT newCustomer(void);

void setTime(customerT customers, int time);
void setPay(customerT customers, float pay);
int getTime(customerT customers);
float getPay(customerT customers);
