#include "gui.h"
#include <gtk/gtk.h>
void clear_child(GtkWidget *container);
void clear_container(int container_id);
void set_prompt(char *);
void show_ingame_buttons();
void hide_ingame_buttons();
char *get_image_path(int card);
void add_image(int container_id, int card);
void quit_game(GtkWindow *window);
void activate(GtkApplication *app, gpointer user_data);

GtkWidget *button_higher;
GtkWidget *frame_box;
GtkWidget *north_container;
GtkWidget *panel_container;
GtkWidget *button_container;
GtkWidget *info_container;
GtkWidget *south_container;
GtkWidget *button_higher;
GtkWidget *button_lower;
GtkWidget *button_new;
GtkWidget *button_quit;
GtkWidget *button_hint;
GtkWidget *button_back;
GtkWidget *button_pass;
GtkWidget *text_prompt;
GtkTextBuffer *buffer_prompt;

int image_archive[2][10];
int north_index;
int south_index;

void on_click_higher();
void on_click_lower();
void on_click_hint();
void on_click_back();
void on_click_pass();
void new_game();

void clear_child(GtkWidget *container)
{
    GList *children, *iter;
    children = gtk_container_get_children(GTK_CONTAINER(container));
    for (iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);
}

void clear_container(int container_id)
{
    if (container_id == 0)
    {
        clear_child(north_container);
        north_index = 0;
    }
    else
    {
        clear_child(south_container);
        south_index = 0;
    }
}

void set_prompt(char *prompt)
{
    gtk_text_buffer_set_text(buffer_prompt, prompt, -1);
}

void show_ingame_buttons()
{
    gtk_widget_show(button_higher);
    gtk_widget_show(button_lower);
    gtk_widget_show(button_hint);
    gtk_widget_show(button_pass);
    gtk_widget_show(button_back);
}

void hide_ingame_buttons()
{
    gtk_widget_hide(button_higher);
    gtk_widget_hide(button_lower);
    gtk_widget_hide(button_hint);
    gtk_widget_hide(button_pass);
    gtk_widget_hide(button_back);
}

char *get_image_path(int card)
{
    /************CODE HERE**************/
    switch (card % 4)
    {
    case 0:
        card += 7;
        break;
    case 1:
        card += 5;
        break;
    case 2:
        card += 2;
        break;
    case 3:
        card += 2;
        break;
    }
    if (card > 51)
    {
        card -= 51;
    }

    char *str = malloc(sizeof(char) * 51);
    sprintf(str, "picture/%d.png", card);
    return str;
    /************CODE END***************/
}

void add_image(int container_id, int card)
{
    GtkWidget *image;
    GtkWidget *container;
    if (container_id == 0)
    {
        container = north_container;
        image_archive[0][north_index++] = card;
    }
    else
    {
        container = south_container;
        image_archive[1][south_index++] = card;
    }
    char *file_name = get_image_path(card);
    image = gtk_image_new_from_file(file_name);
    gtk_container_add(GTK_CONTAINER(container), image);
    gtk_widget_show_all(container);
}

void remove_image(int container_id)
{
    int i, max_i;
    GtkWidget *image;
    GtkWidget *container;
    if (container_id == 0)
    {
        clear_child(north_container);
        container = north_container;
        max_i = --north_index;
    }
    else
    {
        clear_child(south_container);
        container = south_container;
        max_i = --south_index;
    }
    
    for (i = 0; i < max_i; i++)
    {
        char *file_name = get_image_path(image_archive[container_id][i]);
        image = gtk_image_new_from_file(file_name);
        gtk_container_add(GTK_CONTAINER(container), image);
        // printf("+ %d %d\n", image_archive[container_id][i], i);
    }
    gtk_widget_show_all(container);
}

void quit_game(GtkWindow *window)
{
    /************CODE HERE**************/
    // close the game
    gtk_window_close(window);
    /************CODE END***************/
}

void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "HighLow");
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 400);
    int padding = 2;

    frame_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    north_container = gtk_box_new(FALSE, 0);
    panel_container = gtk_box_new(FALSE, 0);
    button_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    info_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    south_container = gtk_box_new(FALSE, 0);
    gtk_container_set_border_width(GTK_CONTAINER(north_container), 20);
    gtk_container_set_border_width(GTK_CONTAINER(panel_container), 20);
    gtk_container_set_border_width(GTK_CONTAINER(button_container), 20);
    gtk_container_set_border_width(GTK_CONTAINER(info_container), 20);
    gtk_container_set_border_width(GTK_CONTAINER(south_container), 20);
    button_higher = gtk_button_new_with_label("Higher!");
    button_lower = gtk_button_new_with_label("Lower!");
    button_new = gtk_button_new_with_label("New Game");
    button_quit = gtk_button_new_with_label("Quit Game");
    button_hint = gtk_button_new_with_label("Hint");
    button_pass = gtk_button_new_with_label("Pass");
    button_back = gtk_button_new_with_label("Back");
    text_prompt = gtk_text_view_new();
    buffer_prompt = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_prompt));

    gtk_container_add(GTK_CONTAINER(window), frame_box);
    gtk_box_pack_start(GTK_BOX(frame_box), north_container, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(frame_box), panel_container, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(panel_container), button_container, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(panel_container), info_container, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(frame_box), south_container, FALSE, FALSE, padding);

    gtk_box_pack_start(GTK_BOX(button_container), button_higher, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(button_container), button_lower, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(button_container), button_new, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(button_container), button_quit, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(button_container), button_hint, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(button_container), button_pass, FALSE, FALSE, padding);
    gtk_box_pack_start(GTK_BOX(button_container), button_back, FALSE, FALSE, padding);
    g_signal_connect_swapped(button_quit, "clicked", G_CALLBACK(quit_game), window);
    gtk_box_pack_start(GTK_BOX(info_container), text_prompt, FALSE, FALSE, padding);

    g_signal_connect(button_new, "clicked", G_CALLBACK(new_game), NULL);
    g_signal_connect(button_higher, "clicked", G_CALLBACK(on_click_higher), NULL);
    g_signal_connect(button_lower, "clicked", G_CALLBACK(on_click_lower), NULL);
    g_signal_connect(button_hint, "clicked", G_CALLBACK(on_click_hint), NULL);
    g_signal_connect(button_pass, "clicked", G_CALLBACK(on_click_pass), NULL);
    g_signal_connect(button_back, "clicked", G_CALLBACK(on_click_back), NULL);
    gtk_text_buffer_set_text(buffer_prompt, "", -1);

    gtk_widget_show_all(window);
    hide_ingame_buttons();
}
