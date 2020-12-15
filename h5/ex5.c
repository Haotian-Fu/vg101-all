#include "assignment.h"

#define ACE 14
#define KING 13
#define QUEEN 12
#define JACK 11

void order();
int cmp(const void *a, const void *b);
int rand_cmp();
void rand_card();
void sort_card();

typedef struct _card{
    int suit;
    int rank;
}card_t;

//card cards[52];

void order(){
    card_t cards[52];
    for(int i=0,cnt=0;i<=3;i++){
        for(int j=2;j<=14;j++,cnt++){
            cards[cnt].suit=i;
            cards[cnt].rank=j;
        }
    }

    char *suit_name[4]={
        "Spades",
        "Hearts",
        "Diamonds",
        "Clubs"
    };

    char *rank_name[14]={
        "2","3","4","5","6","7","8",
        "9","10","JACK","QUEEN","KING","ACE"
    };

    for(int cnt=0;cnt<52;cnt++){
        printf("%s %s\n",suit_name[cards[cnt].suit],rank_name[cards[cnt].rank-2]);
    }
    //printf("\n");
}

int cmp(const void *a, const void *b) {
    int a1,b1,c1,d1;
    a1 = ((const card_t*)a)->suit;
    b1 = ((const card_t*)b)->suit;
    c1 = ((const card_t*)a)->rank;
    d1 = ((const card_t*)b)->rank;
    if((a1-b1)==0){
        if((c1-d1)<0){
            return -1;
        }
    }
    if((a1-b1)<0){
        return -1;
    }
    return 1;

}

int rand_cmp() { 
    return rand() % 2 * 2 - 1;
}

void rand_card(){
    srand((unsigned)time(NULL));
    card_t cards[52];
    for(int i=0,cnt=0;i<=3;i++){
        for(int j=2;j<=14;j++,cnt++){
            cards[cnt].suit=i;
            cards[cnt].rank=j;
        }
    }
    char *suit_name[4]={
        "Spades",
        "Hearts",
        "Diamonds",
        "Clubs"
    };

    char *rank_name[14]={
        "2","3","4","5","6","7","8",
        "9","10","JACK","QUEEN","KING","ACE"
    };
    qsort(cards, 52, sizeof(card_t), rand_cmp); 
    for(int cnt=0;cnt<52;cnt++){
        printf("%s %s\n",suit_name[cards[cnt].suit],rank_name[cards[cnt].rank-2]);
    }
    //printf("\n");
}

void sort_card(){
    card_t cards[52];
    srand((unsigned)time(NULL));
    for(int i=0,cnt=0;i<=3;i++){
        for(int j=2;j<=14;j++,cnt++){
            cards[cnt].suit=i;
            cards[cnt].rank=j;
        }
    }
    char *suit_name[4]={
        "Spades",
        "Hearts",
        "Diamonds",
        "Clubs"
    };

    char *rank_name[14]={
        "2","3","4","5","6","7","8",
        "9","10","JACK","QUEEN","KING","ACE"
    };
    qsort(cards, 52, sizeof(card_t), cmp); 
    for(int cnt=0;cnt<52;cnt++){
        printf("%s %s\n",suit_name[cards[cnt].suit],rank_name[cards[cnt].rank-2]);
    }
}

void ex5(){
    order();
    rand_cmp();
    getchar();
    rand_card();
    getchar();
    sort_card();
}


//#ifdef JOJ
int main(){
    ex5();
    return 0;
}
//endif