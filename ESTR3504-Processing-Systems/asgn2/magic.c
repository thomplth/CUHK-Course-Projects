#include <stdio.h>
#include <string.h>
#include "display.h"
#include <time.h>

int main(int argc, char *argv[]) 
{
   time_t t;
   char temptext[1000];

   // task 1: receive input as the favourite fruit and show messages in message.txt
   printf("First of all, please tell me your favourite fruit: ");
   fgets(temptext, 1000, stdin); 
   temptext[strlen(temptext)-1]='\0'; 
   printf("Your input is: %s\n", temptext);
     

   // initialize GTK before displaying anything on GUI
   init_display(argc, argv);


   // task 2: show an card according to your favourite fruit
   display_text("First, show your lucky card according to your favourite fruit",50,50);
   wait_keypress();
   

   // task 3: card display randomness
   srand((unsigned)time(&t));
  

   return 0;
}
