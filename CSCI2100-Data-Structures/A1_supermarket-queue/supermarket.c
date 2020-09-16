/**
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 * https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name : Lam Tak Hing
 * Student ID : 1155131289
 * Date : 23/02/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "customer.h"

//defining cashiers
struct cashier {
    int numberOfCustomersServed; /* This should be initialized to 0 */
    int totalCustomerWaitingTime; /* This should be initialized to 0 */
    float totalAmountReceived; /* This should be initialized to 0 */
    queueADT customerQ; /* This should be initialized to an empty queue */
    /* This is a Queue of customer structures */
};
typedef struct cashier cashierT;

//main function
int main() {
    /* (1) declare cashiers */
    cashierT cashiers[4];
    
    for(int i = 0; i < 4; i++) {
        cashiers[i].numberOfCustomersServed = 0;
        cashiers[i].totalCustomerWaitingTime = 0;
        cashiers[i].totalAmountReceived = 0;
        cashiers[i].customerQ = EmptyQueue();
    } /* end (1) */
    
    
    /* (2) open supermarket.dat */
    FILE *fp;
    fp = fopen("supermarket.dat", "r");
    
    //check if .dat valid
    if(fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    //obtain data as string
    char str[100][100];
    int lineNo = 0, i = 0;
    while(fgets(str[i],100,fp)) {
        //In case last line is blank
        if(!*str[i])
            continue;
        lineNo++; i++;
    } /* end (2) */
    
    /* (3) declare customers */
    customerT customers[1000];
    float numofCustomer = 0;
    
    //input customer data from string obtained
    for(int i = 0; i < lineNo; i++) {
        if(*str[i] == '\n')
            continue;
        else if(!*str[i])
            continue;
        
        customers[i] = newCustomer();
        numofCustomer++;
        
        char* pEnd;
        setTime(customers[i], (int) strtof(str[i], &pEnd));
        setPay(customers[i], strtof (pEnd, NULL));
    } /* end (3) */
    
    /* (4) process data */
    int checkoutTime[4] = {0};
    int inQueueTime[4][100] = {0};
    int next[4] = {0};
    int inProcess[4] = {0};
    
    //each iteration stands for one minute
    for(int i = 0; i < lineNo ; i++) {
        //check and update cashier status
        for(int j = 0; j < 4; j++) {
            //time past
            if(checkoutTime[j] != 0) {
                checkoutTime[j]--;
                printf("%d check out time %d\n", j, checkoutTime[j]);
                //change status when customer leave
                if(checkoutTime[j] == 0) {
                    inProcess[j] = 0;
                    Dequeue(cashiers[j].customerQ);
                    //move line when next customer exist in queue
                    if(!QueueIsEmpty(cashiers[j].customerQ)) {
                        inProcess[j] = 1;
                        checkoutTime[j] += inQueueTime[j][next[j]];
                        inQueueTime[j][next[j]] = 0;
                        next[j]++;
                        printf("%d check in\n", j);
                    }
                }
            }
        }
        
        //check presence of customer
        if(*str[i] == '\n')
            continue;
        
        //customer selecting cashier with least length & closer to exit
        int least = 0;
        for(int j = 0; j < 3; j++)
            if(QueueLength(cashiers[j + 1].customerQ) < QueueLength(cashiers[least].customerQ))
                least = j + 1;
        
        printf("process %d\n", checkoutTime[least]);
        
        //update cashier with new customer
        cashiers[least].numberOfCustomersServed++;
        cashiers[least].totalCustomerWaitingTime += checkoutTime[least];
        for(int i = 0; i < cashiers[least].numberOfCustomersServed-1; i++)
            cashiers[least].totalCustomerWaitingTime += inQueueTime[least][i];
        cashiers[least].totalAmountReceived += getPay(customers[i]);
        Enqueue(cashiers[least].customerQ, customers[i]);
        
        if(!inProcess[least]) {
            checkoutTime[least] += getTime(customers[i]);
        } else {
            inQueueTime[least][next[least]] += getTime(customers[i]);
        }
        
        inProcess[least] = 1;
        printf("%d %d %d %d\n", cashiers[0].numberOfCustomersServed,cashiers[1].numberOfCustomersServed,cashiers[2].numberOfCustomersServed,cashiers[3].numberOfCustomersServed);
    } /* end (4) */
    
    /* (5) process result */
    float waiting = ((float) cashiers[0].totalCustomerWaitingTime +
                     (float) cashiers[1].totalCustomerWaitingTime +
                     (float) cashiers[2].totalCustomerWaitingTime +
                     (float) cashiers[3].totalCustomerWaitingTime) / numofCustomer ;
    
    //print results
    if(!numofCustomer) {
        printf("The average time a customer needs to wait in queue: \n");
        printf("    0 minute(s)\n");
    } else {
        printf("The average time a customer needs to wait in queue: \n");
        printf("    %.2f minute(s)\n", waiting);
    }
    printf("The total amount of money each of the cashier receives: \n");
    for(int i = 0; i < 4; i++)
        printf("    Cashier %d: $%.2f\n", i, cashiers[i].totalAmountReceived);
    printf("The total number of customers each of the cashier serves: \n");
    for(int i = 0; i < 4; i++)
        printf("    Cashier %d: %d\n", i, cashiers[i].numberOfCustomersServed);
    /* end (5) */
    
    fclose(fp);
    return 0;
}
