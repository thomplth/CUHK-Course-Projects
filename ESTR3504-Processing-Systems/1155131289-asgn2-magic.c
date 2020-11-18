#include <stdio.h>
#include <string.h>
#include "display.h"
#include <time.h>

int main(int argc, char *argv[]) 
{
    time_t t;
    int i, j, k = 0;
    char temptext[1000], msg[1000], l1[1000], l2[1000], l3[1000];
    FILE *txt, *cnt;
    
    // task 1: receive input as the favourite fruit and show messages in message.txt
    printf("First of all, please tell me your favourite fruit: ");
    fgets(temptext, 1000, stdin);
    temptext[strlen(temptext)-1]='\0';
    printf("Your input is: %s\n", temptext);
    int luckyNo = (strlen(temptext) * 2) % 12;
    
    /* .txt inputs */
    txt = fopen("message.txt", "r");
    cnt = fopen("content.txt", "r");
    if (txt == NULL || cnt == NULL){
        printf("Error opening file\n");
        return -1;
    }
    
    // initialize GTK before displaying anything on GUI
    init_display(argc, argv);
    
    for (i = 0; i < 8; i++) {
        fgets(msg, 1000, txt); display_text(msg,50,50);
        if (i == 5) {
            wait_keypress();
            display_david(50, 150);
        }
        wait_keypress();
    }
    
    // task 2: show an card according to your favourite fruit
    move_card_set(50, 150);
    
    display_text("First, show your lucky card according to your favourite fruit",50,50);
    wait_keypress();

    sprintf(msg,"Your lucky card is card %d", luckyNo);
    display_text(msg,50,50);
    display_card(0, luckyNo);
    wait_keypress();
    display_card_clear();
    
    // task 3: card display randomness
    srand((unsigned)time(&t));
    int first[6], second[6];
    int hidden = rand() % 12;
    
    if (hidden % 4 > 2) {
        first[0] = 0;
        first[1] = 1;
        first[2] = 4;
        first[3] = 5;
        first[4] = 8;
        first[5] = 9;
    } else {
        first[0] = 2;
        first[1] = 3;
        first[2] = 6;
        first[3] = 7;
        first[4] = 10;
        first[5] = 11;
    }
    
    for (i = 0; i < 12; i++) {
        if (i == hidden) continue;
        int inFirst = 0;
        for (j = 0; j < 6; j++) {
            if (i == first[j]) {
                inFirst = 1;
                break;
            }
        }
        if (!inFirst) {
            second[k++] = i;
        }
    }
    
    /* para 1 */
    fgets(l1, 1000, cnt); fgets(l2, 1000, cnt); fgets(l3, 1000, cnt);
    strcpy(msg, l1); strcat(msg, l2); strcat(msg, l3);
    display_text(msg,50,50);
    
    for (i = 0; i < 6; i++) {
        display_card(i, first[i]);
    }
    
    wait_keypress();
    fgets(msg, 1000, cnt);
    
    /* para 2 */
    fgets(l1, 1000, cnt); fgets(l2, 1000, cnt); fgets(l3, 1000, cnt);
    strcpy(msg, l1); strcat(msg, l2); strcat(msg, l3);
    display_text(msg,50,50);
    wait_keypress();
    fgets(msg, 1000, cnt);

    /* para 3 */
    fgets(l1, 1000, cnt); fgets(l2, 1000, cnt); fgets(l3, 1000, cnt);
    strcpy(msg, l1); strcat(msg, l2); strcat(msg, l3);
    display_card_clear();
    display_text(msg,50,50);
    display_david(50,150);
    wait_keypress();
    fgets(msg, 1000, cnt);

    /* para 4 */
    fgets(l1, 1000, cnt); fgets(l2, 1000, cnt);
    strcpy(msg, l1); strcat(msg, l2);
    display_text(msg,50,50);
    wait_keypress();
    fgets(msg, 1000, cnt);

    /* para 5 */
    fgets(l1, 1000, cnt); fgets(l2, 1000, cnt);
    strcpy(msg, l1); strcat(msg, l2);
    display_text(msg,50,50);
    wait_keypress();
    fgets(msg, 1000, cnt);

    /* para 6 */
    fgets(l1, 1000, cnt);
    display_text(l1,50,50);
    
    for (i = 0; i < 5; i++) {
        display_card(i, second[i]);
    }
    
    wait_keypress();
    fgets(msg, 1000, cnt);

    /* para 7 */
    fgets(l1, 1000, cnt); fgets(l2, 1000, cnt);
    strcpy(msg, l1); strcat(msg, l2);
    display_text(msg,50,50);
    wait_keypress();
    fgets(msg, 1000, cnt);

    /* para 8 */
    fgets(l1, 1000, cnt); fgets(l2, 1000, cnt);
    strcpy(msg, l1); strcat(msg, l2);
    display_text(msg,50,50);
    wait_keypress();
    fgets(msg, 1000, cnt);

    /* para 9 */
    fgets(l1, 1000, cnt);
    display_text(l1,50,50);
    wait_keypress();
    fgets(msg, 1000, cnt);

    fclose(txt);
    fclose(cnt);
    
    return 0;
}

