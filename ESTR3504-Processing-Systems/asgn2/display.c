/* **************************************************** */
/* You SHOULD NOT modify this file for this assignment! */
/* **************************************************** */

#include "display.h"
#include <gtk/gtk.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <gdk/gdkkeysyms.h>

/* GtkWidget is the storage type for widgets */
GtkWidget *window;
GtkWidget *fixed;
GtkWidget *cards;
GtkWidget *cards_image[MAX_CARD_TO_HOLD];   /* store the image pointers displayed */
GtkWidget *text_display;

int keypressed = 0;
int signal_is_waiting_event=false;
int signal_is_window_destroyed=SIGNAL_IS_NOT_WINDOW_DESTROYED;

void destroy(GtkWidget *widget,gpointer data)
{
    if (signal_is_waiting_event==false)
       gtk_main_quit();
    else
       signal_is_window_destroyed=SIGNAL_IS_WINDOW_DESTROYED;
}

static gboolean key_event(GtkWidget *widget, GdkEventKey *event) 
{
   switch (event->keyval) 
     {
       case GDK_KEY_space:
           keypressed = 1;
           break;
       default:
           return FALSE;
      }
   return FALSE;
}

void display_card_clear() {
  int j;
  for (j=0;j<MAX_CARD_TO_HOLD;j++) {
    if (cards_image[j] != NULL) {
      gtk_widget_destroy ((GtkWidget*)cards_image[j]);
      cards_image[j] = NULL;
    }
  }
}

void display_card(int position, int card_id) {
  char temp[18];
  GtkWidget *image;
  sprintf(temp,"card/%d.png",card_id);
  image = gtk_image_new_from_file (temp);
  if (cards_image[position] != NULL) {
    gtk_widget_destroy (cards_image[position]);
  }
  gtk_table_attach_defaults (GTK_TABLE (cards), image, position, position+1, 0, 1);
  cards_image[position] = image;
  gtk_widget_show (image);
}

void display_david(int x, int y){
  GtkWidget *image;
  display_card_clear();
  image = gtk_image_new_from_file ("david.jpg");
  gtk_table_attach_defaults (GTK_TABLE (cards), image, 0, 1, 0, 1);
  cards_image[0] = image;
  gtk_widget_show (image);
  move_card_set(x, y);
}

void move_card_set(int x, int y) {
  gtk_fixed_move(GTK_FIXED(fixed),GTK_WIDGET(cards),x,y);
}

void display_text(char *message, int x, int y) {
  char tagstring[1000];
  sprintf(tagstring,"<span stretch=\"expanded\" size='%d'>",16*1200);
  strcat(tagstring,message);
  strcat(tagstring,"</span>");
  gtk_fixed_move(GTK_FIXED(fixed),GTK_WIDGET(text_display),x,y);
  gtk_label_set_markup((GtkLabel*)text_display,tagstring);
}

void init_display(int argc, char *argv[]) {
  /* This is called in all GTK applications. Arguments are parsed
   * from the command line and are returned to the application. */

  // create a window
  gtk_init(&argc,&argv);
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Magic");
  gtk_window_set_default_size(GTK_WINDOW (window), 800, 600);
  gtk_container_set_border_width (GTK_CONTAINER (window), 10);

  /* key press eevnt */
  g_signal_connect(G_OBJECT (window), "key-release-event", G_CALLBACK(key_event), NULL);

  /* Event of the close window button */
  g_signal_connect(G_OBJECT (window),"destroy", GTK_SIGNAL_FUNC (destroy), NULL);  
  g_signal_connect(G_OBJECT (window),"delete-event",GTK_SIGNAL_FUNC (destroy), NULL);

  
  // create a fixed container
  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), fixed);
  text_display = gtk_label_new ("");
  gtk_fixed_put(GTK_FIXED(fixed), text_display, 50, 50);

  //g_signal_connect(G_OBJECT (fixed),"destroy", G_CALLBACK(gtk_widget_destroy), NULL);  
  g_signal_connect(G_OBJECT (fixed),"destroy", G_CALLBACK(gtk_widget_destroy), G_OBJECT (window));  
  g_signal_connect(G_OBJECT (fixed),"delete-event",G_CALLBACK(gtk_widget_destroy), G_OBJECT (window));

  // create a table
  cards = gtk_table_new (1, MAX_CARD_TO_HOLD, FALSE);
  gtk_table_set_col_spacings (GTK_TABLE (cards), 0);
  gtk_fixed_put(GTK_FIXED(fixed), GTK_WIDGET(cards),50,50);

  gtk_widget_show_all (window);
}

int wait_keypress() 
{
   keypressed = 0;
   signal_is_window_destroyed=SIGNAL_IS_NOT_WINDOW_DESTROYED;
   signal_is_waiting_event=true;

   while (keypressed == 0)
     {
         while (gtk_events_pending()) 
             gtk_main_iteration();

         if (signal_is_window_destroyed==SIGNAL_IS_WINDOW_DESTROYED)
             return SIGNAL_IS_WINDOW_DESTROYED;
         g_usleep (1000);
     }
   signal_is_waiting_event=false;

   return SIGNAL_IS_NOT_WINDOW_DESTROYED;
}


void wait_time(double seconds) {
  double t;
  t=time(NULL)+seconds;
  while (time(NULL)<t) {
    while (gtk_events_pending()) gtk_main_iteration();
  }
}
