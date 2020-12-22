#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

typedef struct _card
{
    int suit;
    int rank;
} card_t;

typedef struct _stockpile
{
    card_t *s_card;
    int memory; //how many cards are in the stock
} stockpile_t;

typedef struct _player
{
    int score;
    int card_mem; //how many cards do you have
    card_t *p_card;
    // data part

    struct _player *next;
    struct _player *prev;
    //pointer part
} player_t;

typedef struct _gameint
{
    int round;
    int winner;
    int *score;
} gameint_t;

//DONT FORGET DEFINE FUNCTIONS
void welcome();
void help();
int rand_cmp();
void shuffle_card(int d, card_t *card);
void showplayercard(card_t *card, int card_mem, int turn);
void show1card(card_t showcard);
void cardjudge(int num, card_t *p_card, card_t *top);

#endif