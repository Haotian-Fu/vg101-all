#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef __WIN32
#define CLEAR()        \
    do                 \
    {                  \
        system("cls"); \
    } while ((void)0, 0)
#else
#define CLEAR()          \
    do                   \
    {                    \
        if(!system("clear")){}; \
    } while ((void)0, 0)
#endif

#ifndef __INVOKE_IGNORE_RETURN
#define __INVOKE_IGNORE_RETURN(command) \
while (command) {break;}
#endif

#define ACE 14
#define KING 13
#define QUEEN 12
#define JACK 11

//welcome part

void welcome()
{
    printf("        ########################\n");
    printf("        #                      #\n");
    printf("        # Welcome to One Card! #\n");
    printf("        #                      #\n");
    printf("        ########################\n");
    printf("===========================================\n\n\n\n\n");
}

void help()
{
    printf("************************************Welcome to OneCard!*****************************************\n");
    printf("-h|    --help             Print this help message\n");
    printf("--log|  filename          Write the logs in filename                      (default: onecard.log)\n");
    printf("-n n|  --player-number=n  n players, n must be larger than 2              (default: 4)\n");
    printf("-c c|  --initial-cards=c  Deal c cards per player, c must be at least 2   (default: 5)\n");
    printf("-d d|  --decks=d          Use d decks 52 cards each, d must be at least 2 (default: 2)\n");
    printf("-r r|  --rounds=r         Play r rounds, r must be at least 1             (default: 1)\n");
    printf("-a|    --auto             Run in demo mod\n");
    printf("************************************************************************************************\n");
}

//return a random +-1
int rand_cmp()
{
    return rand() % 2 * 2 - 1;
}

//shuffle cards
void shuffle_card(int d, card_t *card)
{
    srand((unsigned)time(NULL));
    int cnt = 0;
    for (int deck = 0; deck < d; deck++)
    {
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 2; j <= 14; j++, cnt++)
            {
                card[cnt].suit = i;
                card[cnt].rank = j;
            }
        }
    }
    qsort(card, (long unsigned int)(52 * d), sizeof(card_t), rand_cmp);
}

void showplayercard(card_t *card, int card_mem, int turn)
{
    char *suit_name[4] = {
        "Spades",
        "Hearts",
        "Diamonds",
        "Clubs"};

    char *rank_name[14] = {
        "2", "3", "4", "5", "6", "7", "8",
        "9", "10", "JACK", "QUEEN", "KING", "ACE"};
    printf("Player %d's cards:\n", turn);
    for (int c = 0; c < card_mem; c++)
    {
        int suit = card[c].suit;
        int rank = card[c].rank;
        printf("[%d] %s %s\n", c, suit_name[suit], rank_name[rank]);
    }
    printf("\n");
}

void show1card(card_t showcard)
{
    char *suit_name[4] = {
        "Spades",
        "Hearts",
        "Diamonds",
        "Clubs"};

    char *rank_name[14] = {
        "2", "3", "4", "5", "6", "7", "8",
        "9", "10", "JACK", "QUEEN", "KING", "ACE"};
    int suit = showcard.suit;
    int rank = showcard.rank;
    printf("%s %s\n", suit_name[suit], rank_name[rank]);
}

void cardjudge(int num, card_t *p_card, card_t *top)
{
    if (num != -1)
    {
        card_t *drawcard=malloc(sizeof(card_t *));
        *drawcard = p_card[num];
        while (drawcard->rank != top->rank || drawcard->suit != top->suit)
        {
            printf("Invalid input! Please draw again!\n");
            while(!scanf("%d", &num));
            cardjudge(num, p_card, top);
        }
    }
}

// change parameters
int main(int argc, char *argv[])
{
    welcome();
    int c = 5;
    int d = 2;
    int p = 4;
    int r = 1;
    int a = 0;
    // card,decks,player,round,auto
    char logname[32] = "onecard.log";
    for (int i = 1; i < argc; i++)
    {
        if ((argv[i][0]) != '-')
        {
            printf("WRONG, please re-input");
            return 1;
        }
        switch (*(argv[i] + 1))
        {
        case 'h':
            help();
            return 0;
        case '-':
            if (*(argv[i] + 2) == 'l' && *(argv[i] + 3) == 'o' && *(argv[i] + 4) == 'g')
            {
                i++;
                sprintf(logname, "%s", argv[i]);
                return 0;
            }
            break;
        case 'c':
            c = atoi(argv[i + 1]);
            i++;
            break;
        case 'd':
            d = atoi(argv[i + 1]);
            i++;
            break;
        case 'n':
            p = atoi(argv[i + 1]);
            i++;
            break;
        case 'r':
            r = atoi(argv[i + 1]);
            i++;
            break;
        case 'a':
            a = 1;
            break;
        default:
            printf("Invalid input!");
            break;
        }
    }

    FILE *fp = fopen(logname, "w");
    printf("---- Initial setup ----\n Number of initial cards: %d\n Number of decks: %d\n Number of players: %d\n "
           "Number of rounds: %d\n File name of log :%s\n If demo mode:%d\n",
           c, d, p, r, logname,a);
    fprintf(fp, "---- Initial setup ----\n Number of initial cards: %d\n Number of decks: %d\n Number of players: %d\n "
                "Number of rounds: %d\n File name of log :%s\n If demo mode:%d\n",
            c, d, p, r, logname,d);
    //write in the log file
    //************************welcome part************************

    // gameint_t gameint;
    // gameint.round = 0;
    for (int round = 0; round < r; round++)
    {
        // gameint.round = round;
        player_t *player1 = malloc((unsigned)(p) * sizeof(player_t));
        for (int i = 0; i < p; i++)
        {
            player1[i].p_card = malloc((unsigned)(52 * d) * sizeof(card_t *));
            player1[i].card_mem = c;
        }

        //init card
        stockpile_t stockpile1;
        stockpile1.s_card = (card_t *)malloc((unsigned)(d * 52) * sizeof(card_t *));
        shuffle_card(d, stockpile1.s_card);
        stockpile1.memory = d * 52 - c * p;
        printf("\nShuffling cards...\n\n\n");
        fprintf(fp, "\nShuffling cards...\n\n\n");
        //init discard pile
        // stockpile_t discardpile1;
        // discardpile1.s_card = malloc((unsigned)(d * 52) * sizeof(card_t *));
        // discardpile1.memory = 0;

        //send player initial cards
        for (int n = 0; n < p; n++)
        {
            for (int i = 0; i < c; i++)
            {
                player1[n].p_card[i] = stockpile1.s_card[5 * n + i];
            }
        }

        //define a card to start
        card_t *topcard = malloc(sizeof(card_t *));
        *topcard = stockpile1.s_card[p * c];

        //define the start order
        srand((unsigned)time(NULL));
        int start_order = rand() % (p);
        int win_num = 0;
        //int attack = 0;
        //int direction = 1; //counterwise
        //************************game start!************************
        printf("-------Game Start!--------\n");
        fprintf(fp, "-------Game Start!--------\n");
        printf("\nPress Enter to continue\n");
        printf("The game will start from Player %d\n",start_order+1);
        getchar();
        
        for (int i = 0; i < p; i++)
        {
            while (player1[i].card_mem != 0)
            {
                CLEAR();
                
                int player_num;
                int card_num;
                printf("Please enter your player number:\n");
                while(!scanf("%d", &player_num));
                while (player_num > p)
                {
                    printf("Invalid input! Please input again!\n");
                    while(!scanf("%d", &player_num));
                }
                CLEAR();
                printf("Player %d's turn:\n", player_num);
                printf("topcard is:");
                show1card(*topcard);
                showplayercard(player1[player_num - 1].p_card, player1[player_num - 1].card_mem, player_num);
                printf("You need to play one card(or enter -1 to skip this turn):\n");
                while(!scanf("%d", &card_num));

                //cardjudge(card_num, player1[player_num].p_card, topcard);

                CLEAR();
            }
            break;
            win_num = i;
        }
        printf("Player %d wins this round", win_num);
        //showscore(player1,gameint);
    }
}
