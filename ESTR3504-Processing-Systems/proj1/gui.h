#include <gtk/gtk.h>

void clear_child(GtkWidget*);
void clear_container(int);
void set_prompt(char*);
void show_ingame_buttons();
void hide_ingame_buttons();
char *get_image_path(int);
void add_image(int, int);
void remove_image(int);
void quit_game(GtkWindow*);
void activate(GtkApplication*, gpointer);