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
#include "stack.h"

//identify opening parenthese, brace or square bracket
//return its closing version
char checkLeftType(char str) {
    if(str == '(')
        return ')';
    else if(str == '{')
        return '}';
    else if(str == '[')
        return ']';
    else return 0;
}

//featured function to check if the string of parentheses is well-formated
int checkBalance(stackADT stack, char str[]) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            Push(stack, str[i]);
        } else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if(StackIsEmpty(stack))
                return 0;
            if(str[i] == checkLeftType(Pop(stack)))
                continue;
        }
    }
    
    if(StackIsEmpty(stack))
        return 1;
    else
        return 0;
}

int main() {
    char str[100];
    
    printf("Please input the string of parenthesis:\n");
    fgets(str, 100, stdin);
    
    stackADT stack;
    stack = EmptyStack();
    
    if(checkBalance(stack, str)) {
        printf("Yes, the input is a well-formed string of parentheses.\n");
    } else {
        printf("No, the input is NOT a well-formed string of parentheses.\n");
    }
    
    return 0;
}
