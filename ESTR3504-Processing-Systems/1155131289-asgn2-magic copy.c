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
    int hidden = rand() % 12;
    int hiddenK = hidden % 4;
    int hiddenN = hidden / 4;
    
    /* para 1 */
    fgets(l1, 1000, cnt); fgets(l2, 1000, cnt); fgets(l3, 1000, cnt);
    strcpy(msg, l1); strcat(msg, l2); strcat(msg, l3);
    display_text(msg,50,50);
    
    for (i = 2; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            int cardNo = ((hiddenK+i)%4) + 4 * ((hiddenN+j)%3);
//            printf("%d\n", cardNo);
            display_card(k++, cardNo);
        }
    }
    k = 0;
//    printf("\n");
    
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
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            int cardNo = ((hiddenK+i)%4) + 4 * ((hiddenN+j)%3);
//            printf("%d\n", cardNo);
            if (cardNo != hidden) {
                display_card(k++, cardNo);
            }
        }
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

