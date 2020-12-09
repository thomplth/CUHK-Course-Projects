#include "gui.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
int add_new_card(int container_id, int step);
char *get_prompt();
void new_game();
void card_shuffle();
void end_game();
void higher_lower(int is_higher);
void on_click_higher();
void on_click_lower();
void on_click_hint();

static int status[3]; // step, North's score, South's score
static int card_deck[52];
const int rounds = 19;
char prompt[100];

static int last_choice[100]; // -1: passed, 0: lower, 1: higher
static int choice_index;

// container_id = 0 for North, 1 for South
int add_new_card(int container_id, int step)
{
    int card = card_deck[step];
    // printf("%d %d\n", card, step);
    add_image(container_id, card);
    return card;
}

char *get_prompt()
{
    char north[] = "North";
    char south[] = "South";
    sprintf(prompt, "%s's turn\nNorth's score : %d\nSouth's score: %d", (status[0] % 2 == 0 ? north : south), status[1], status[2]);
    return prompt;
}

void new_game()
{
    /************CODE HERE**************/
    // starts a new game,
    // all initialization useful for resetting should be done here
    // Hint:
    // 1. please don't forget the situation when we finish a game and start a new one.
    // 2. We should have two cards already shown at the start of the game.

    // Create a new game. It should
    // 1) initialize the status variable;
    status[0] = 0;
    status[1] = 0;
    status[2] = 0;
    
    int i;
    for (i = 0; i < 100; i++)
    {
        last_choice[i] = 0;
    }
    choice_index = 0;

    // 2) Clear north and south container;
    clear_container(0);
    clear_container(1);

    // 3) Set the initial prompt;
    set_prompt(get_prompt());

    // 4) Shuffle the card deck;
    card_shuffle();

    // 5) Add initial card for north and south player;
    add_new_card(0, status[0]++);
    add_new_card(1, status[0]++);

    // 6) Show ingame buttons.
    show_ingame_buttons();

    /************CODE END***************/
}

void card_shuffle()
{
    // this method prepares all cards in card_deck
    // this is the ONLY function that should apply RANDOMNESS
    int i, irandom, temp;
    for (i = 0; i < 52; i++)
    {
        card_deck[i] = i;
    }
    for (i = 0; i < 51; i++)
    {
        irandom = i + rand() % (52 - i);
        temp = card_deck[i];
        card_deck[i] = card_deck[irandom];
        card_deck[irandom] = temp;
    }
}

void end_game()
{
    /************CODE HERE**************/
    // 1. Hide the higher and lower button
    hide_ingame_buttons();

    // 2. show match results in buffer_prompt.
    // If North wins, Please show "North wins.\nNorth's score : %d, South's score: %d"
    char north[] = "North";
    char south[] = "South";

    if (status[1] > status[2])
    {
        sprintf(prompt, "%s wins.\nNorth's score : %d, South's score: %d", north, status[1], status[2]);
    }
    else if (status[1] < status[2])
    {
        sprintf(prompt, "%s wins.\nNorth's score : %d, South's score: %d", south, status[1], status[2]);
    }
    else
    {
        sprintf(prompt, "Draw.\nNorth's score : %d, South's score: %d", status[1], status[2]);
    }
    set_prompt(prompt);

    /************CODE END***************/
}

void higher_lower(int is_higher)
{
    int step = status[0];
    int current_container = step % 2;
    int card = add_new_card(current_container, step);

    /************CODE HERE**************/
    // If current player predict correct card, he get 10 points. Otherwise, he loss 5 points.

    // Game logicals for users if they press higher or lower. It will:
    // 1) Draw a new card from the card container;
    // 2) Calculate the score for the player;
    int prev_card = card_deck[step - 1];

    if (is_higher)
    {
        if (card > prev_card)
        {
            status[current_container + 1] += 10;
        }
        else
        {
            status[current_container + 1] -= 5;
        }
    }
    else
    {
        if (card < prev_card)
        {
            status[current_container + 1] += 10;
        }
        else
        {
            status[current_container + 1] -= 5;
        }
    }

    // 3) Update the status variable.
    /************CODE END***************/

    if (status[0] == rounds)
    {
        end_game();
        return;
    }
    else
    {
        status[0]++;
        char *prompt = get_prompt();
        set_prompt(prompt);
    }
}

void on_click_higher()
{
    higher_lower(1);
    last_choice[choice_index++] = 1;
}

void on_click_lower()
{
    higher_lower(0);
    last_choice[choice_index++] = 0;
}

void on_click_hint()
{
    int prev_card = card_deck[status[0] - 1];
    int higher = 0, lower = 0, i;

    for (i = status[0]; i < 52; i++)
    {
        if (card_deck[i] > prev_card)
        {
            higher++;
        }
        else
        {
            lower++;
        }
    }

    char hint[100];
    char *prompt = get_prompt();
    sprintf(hint, "%s\n\n%d card(s) in deck are higher\n%d card(s) in deck are lower", prompt, higher, lower);
    set_prompt(hint);
}

void on_click_pass()
{
    int step = status[0];
    int current_container = step % 2;
    int card = add_new_card(current_container, step);

    if (status[0] == rounds)
    {
        end_game();
        return;
    }
    else
    {
        status[0]++;
        char *prompt = get_prompt();
        set_prompt(prompt);
    }
    last_choice[choice_index++] = -1;

    // printf("%d %d\n", card, step);
}

void on_click_back()
{
    if (status[0] <= 2)
        return;

    int card = card_deck[--status[0]];
    int prev_card = card_deck[status[0]-1];
    int container = status[0] % 2;
    int choice = last_choice[--choice_index];

    remove_image(container);

    // printf("%d %d\n", card, prev_card);

    if (choice == 1)
    {
        if (card > prev_card)
        {
            status[container + 1] -= 10;
            // printf("- %d %d\n", card, status[0]);
        }
        else
        {
            status[container + 1] += 5;
            // printf("+ %d %d\n", card, status[0]);
        }
    }
    else if (choice == 0)
    {
        if (card < prev_card)
        {
            status[container + 1] -= 10;
            // printf("- %d %d\n", card, status[0]);
        }
        else
        {
            status[container + 1] += 5;
            // printf("+ %d %d\n", card, status[0]);
        }
    }

    char *prompt = get_prompt();
    set_prompt(prompt);
}