//
//  main.c
//  Vending Machine
//
//  Created by ThompsonLam on 16/11/2019.
//

#include <stdio.h>

int pass = 1110;
int revenue = 0;
int deposite = 0;

char item = '=';

char name[5][20] = {"Juice", "Cola", "Tea", "Water", "Coffee"};
int price[5] = {10, 6, 5, 8, 7};
int num[5] = {5, 1, 2, 1, 9};

// print vending machine
void display() {
    char a = ' ', b = ' ', c = ' ', d = ' ', e = ' ';
    
    if(deposite >= price[0] && num[0] > 0) a = 'O';
    else if(num[0] == 0) a = 'X';
    if(deposite >= price[1] && num[1] > 0) b = 'O';
    else if(num[1] == 0) b = 'X';
    if(deposite >= price[2] && num[2] > 0) c = 'O';
    else if(num[2] == 0) c = 'X';
    if(deposite >= price[3] && num[3] > 0) d = 'O';
    else if(num[3] == 0) d = 'X';
    if(deposite >= price[4] && num[4] > 0) e = 'O';
    else if(num[4] == 0) e = 'X';
    
        printf("*---------------------------*\n");
        printf("|      Vending Machine      |\n");
        printf("*---------------------------*\n");
        printf("|   A    B    C    D    E   |\n");
        printf("|  $%2d  $%2d  $%2d  $%2d  $%2d  |\n", price[0], price[1], price[2], price[3], price[4]);
        printf("|  [%c]  [%c]  [%c]  [%c]  [%c]  |\n", a, b, c, d, e);
        printf("*---------------------------*\n");
        printf("|                    [$%2d]  |\n", deposite);
        printf("|                           |\n");
        printf("|           [=%c=]           |\n", item);
        printf("*---------------------------*\n");
    
    item = '=';
}

// menu option 1
void info() {
    printf("\n(1) The displayed products are:\n");
    printf("A. %s ($%d)\n", name[0], price[0]);
    printf("B. %s ($%d)\n", name[1], price[1]);
    printf("C. %s ($%d)\n", name[2], price[2]);
    printf("D. %s ($%d)\n", name[3], price[3]);
    printf("E. %s ($%d)\n\n", name[4], price[4]);
}

// menu option 2
void charge() {
    int opt2 = 99;
    int coin = 0;
    
    while(opt2 != 0) {
        printf("\n(2) Which coin would you like to insert?\n");
        printf("1. $1\n");
        printf("2. $2\n");
        printf("3. $5\n");
        printf("4. $10\n");
        printf("0. Go back\n");
        
        printf("Your choice: ");
        scanf("%d", &opt2);
        
        if(opt2 == 1) coin = 1;
        else if(opt2 == 2) coin = 2;
        else if(opt2 == 3) coin = 5;
        else if(opt2 == 4) coin = 10;
        else if(opt2 == 0) {
            printf("Going back!\n\n");
            display();
            printf("\n");
            break;
        } else if(opt2 < 0 || opt2 > 4) {
            printf("Invalid choice!\n");
            continue;
        }
        
        deposite += coin;
        if(deposite > 99)
            deposite = 99;
        
        printf("You have inserted $%d.\n\n", coin);
        display();
    } // exit when user input 0
}

// dispense product
void dispence(int opt) {
    char product = opt + 64;
    printf("You have pressed button %c.\n\n", product);
    
    if(deposite >= price[opt - 1] && num[opt - 1] > 0) {
        item = product;
        deposite -= price[opt - 1];
        num[opt - 1]--;
        revenue += price[opt - 1];
    }
    
    display();
}

// menu option 3
void product() {
    int opt3 = 99;
    
    while(opt3 != 0) {
        printf("\n(3) Which product button would you like press\n");
        printf("1. A\n");
        printf("2. B\n");
        printf("3. C\n");
        printf("4. D\n");
        printf("5. E\n");
        printf("0. Go back\n");
        
        printf("Your choice: ");
        scanf("%d", &opt3);
        
        if(opt3 == 0) {
            printf("Going back!\n\n");
            break;
        } else if(opt3 < 0 || opt3 > 5) {
            printf("Invalid choice!\n");
            continue;
        }
        
        dispence(opt3);
    } // exit when user input 0
}

// menu option 4
void change() {
    printf("\n(4) Return button is pressed.\n");
    printf("$%d has been returned.\n\n", deposite);
    display();
    printf("\n");
    
    deposite = 0;
}

// service menu 1
void sStatus() {
    printf("\n(9-1) Machine status\n");
    printf("Amount of revenue: %d\n", revenue);
    printf("Amount of inserted coins: %d\n", deposite);
    printf("Product information:\n");
    printf("A. %s ($%d) (%d left)\n", name[0], price[0], num[0]);
    printf("B. %s ($%d) (%d left)\n", name[1], price[1], num[1]);
    printf("C. %s ($%d) (%d left)\n", name[2], price[2], num[2]);
    printf("D. %s ($%d) (%d left)\n", name[3], price[3], num[3]);
    printf("E. %s ($%d) (%d left)\n", name[4], price[4], num[4]);
}

// service menu 2
void sWithdraw() {
    printf("\n(9-2) All money is being withdrawn.\n");
    printf("$%d is withdrawn.\n", revenue + deposite);
    
    revenue = 0;
    deposite = 0;
}

// service menu 3
void sRefill() {
    int sOpt3 = 99;
    
    while(sOpt3 != 0) {
        printf("\n(9-3) Which product would you like to refill?\n");
        printf("1. A\n");
        printf("2. B\n");
        printf("3. C\n");
        printf("4. D\n");
        printf("5. E\n");
        printf("0. Go back\n");
        
        printf("Your choice: ");
        scanf("%d", &sOpt3);
        
        if(sOpt3 == 0) {
            printf("Going back!\n\n");
            break;
        } else if(sOpt3 < 0 || sOpt3 > 5) {
            printf("Invalid choice!\n");
            continue;
        }
        
        num[sOpt3 - 1] = 99;
        printf("You have refilled product %c to full\n", sOpt3 + 64);
        return;
    }
}

// service menu 4
void sChange() {
    int sOpt4 = 99;
    
    while(sOpt4 != 0) {
        printf("\n(9-3) Which product would you like to change?\n");
        printf("1. A\n");
        printf("2. B\n");
        printf("3. C\n");
        printf("4. D\n");
        printf("5. E\n");
        printf("0. Go back\n");
        
        printf("Your choice: ");
        scanf("%d", &sOpt4);
        
        if(sOpt4 == 0) {
            printf("Going back!\n\n");
            break;
        } else if(sOpt4 < 0 || sOpt4 > 5) {
            printf("Invalid choice!\n");
            continue;
        }
        
        printf("You are changing product %c.\n", sOpt4 + 64);
        
        printf("\n(9-4-1) Changing product\n");
        
        printf("Enter new product name: ");
        scanf("%s", &name[sOpt4 - 1][0]);
        printf("Enter new product price: ");
        scanf("%d", &price[sOpt4 - 1]);
        
        num[sOpt4 - 1] = 99;
        printf("The new product %c has been refilled to full.\n", sOpt4 + 64);
        return;
    }
}

// menu option 9
void service() {
    int input;
    printf("\n(9) Opening service menu. Access code is required.\n");
    
    printf("Enter access code: ");
    scanf("%d", &input);
    
    if(pass == input) {
        printf("Correct code!\n");
    } else {
        printf("Incorrect code!\n");
        display();
        printf("\n");
        return;
    }
    
    while(input != 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Inspect machine status\n");
        printf("2. Withdraw all money\n");
        printf("3. Refill product\n");
        printf("4. Change product\n");
        printf("0. Go back\n");
        
        printf("Your choice: ");
        scanf("%d", &input);
        
        if(input == 1) sStatus();
        else if(input == 2) sWithdraw();
        else if(input == 3) sRefill();
        else if(input == 4) sChange();
        else if(input == 0)  {
            printf("Going back!\n\n");
            break;
        } else if(input < 0 || input > 4) {
            printf("Invalid choice!\n");
            continue;
        }
    }
}

// main function
int main(void) {
    display();
    printf("\n");
    
    int input = 99;
    while(input != 0) {
        // print menu
        printf("What would you like to do?\n");
        printf("1. Read product information\n");
        printf("2. Insert coin\n");
        printf("3. Press product button\n");
        printf("4. Press return button\n");
        printf("9. Open service menu (code required)\n");
        printf("0. Quit\n");
        
        printf("Your choice: ");
        scanf("%d", &input);
        
        if(input == 1) info();
        else if(input == 2) charge();
        else if(input == 3) product();
        else if(input == 4) change();
        else if(input == 9) service();
        else if(input == 0) break;
        else printf("Invalid choice!\n\n");
    } // exit when user input 0
    
    return 0;
}
