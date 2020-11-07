#define MAX_CARD_TO_HOLD 6
#define true 1
#define false 0
#define SIGNAL_IS_WINDOW_DESTROYED false
#define SIGNAL_IS_NOT_WINDOW_DESTROYED true

void init_display(int argc, char *argv[]);
void display_text(char *message, int x, int y);
void display_card(int position, int card_id);
void display_david(int x, int y);
void display_card_clear();
void move_card_set(int x, int y);
int wait_keypress();
