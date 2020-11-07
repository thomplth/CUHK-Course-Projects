#include <stdio.h>
#include "display.h"
#include <time.h>

int main(int argc, char *argv[]) 
{
   int i;
   time_t t;
   char temptext[1000];

   srand((unsigned)time(&t));

   printf("Hello! Your input: ");

   //read the input from user (maximum 1000 characters)
   fgets(temptext, 1000, stdin);
   printf("Your input is: %s", temptext);

   init_display(argc, argv);

   for (i=0; i<5; i++) 
      {
        //set the content of variable temptext to: Slide [i+1]
        sprintf(temptext,"Slide %d",i+1);
        
        /* call the function display_text to display the content in variable temptext, 
         the coordinate (top left corner) of the text is x = i*10 and y = 100 */
        display_text(temptext,i*10,100);

        //clear all image on the table to be shown
        display_card_clear();
        
        if (i%3!=0) 
          {
            //the following code will be executed only if i is 1 or 2
            //set the location of the image before displaying it
            move_card_set(50,200);
            
            /* call the function display_card to display the card [rand()%12] 
             rand() is a function that generates a random integer
             % is a modulus operation that returns the remainder after dividing the number by 12
             so the remainder will be always between 0 to 11)
            */
          
            /* table[0] will store card X.png where X equals to rand()%12, 
             and display_card will display images according to contents in table 
             function display_card_clear will clear the content of table */
            display_card(0,rand()%12);
          
            //call the functin again to display another card
            //so now there are two cards in the table to be shown if rand()%6 is not 0
            display_card(rand()%6,rand()%12);
          }

        //wait until the next input(space key by default), no need to care about returned value
        wait_keypress();
      }

   // display a empty string can clear text shown on GUI previously
   display_text("",40,100);
   // call the function display_david to display the photo of David  
   display_david(50,100);
   wait_keypress(); 
   
   return 0;
}
