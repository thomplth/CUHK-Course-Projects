/*
Customer.c
*/
#include "customer.h"
#include <stdlib.h>
#include <stdio.h>

struct customer {
    int checkoutTime;
    float payment;
};

customerT newCustomer(void) {
    customerT customers;
    
    customers = (customerT)malloc(sizeof(customers));
    customers->checkoutTime = 0;
    customers->payment = 0;
    return(customers);
}

void setTime(customerT customers, int time) {
    customers->checkoutTime = time;
}

void setPay(customerT customers, float pay) {
    customers->payment = pay;
}

int getTime(customerT customers) {
    return customers->checkoutTime;
}

float getPay(customerT customers) {
    return customers->payment;
}
