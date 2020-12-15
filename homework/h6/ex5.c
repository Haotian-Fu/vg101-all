#include "universal_set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void newSet(uset **set, int type) {
    (*set)->type=type;
    (*set)->elem = malloc((size_t)type*INITSETSIZE*100);
    (*set)->card = 0;
}

void deletSet(uset **set) {
    free((*set)->elem);
    free(*set);
}

/* add elem to the set: check whether it is already in the set;
resize memory if card = allocated memory; new memory = previous+64
e.g. before: mem=128, card=128, after: men=192, card=129 */
void addElem(void *elem, uset *set) {
    int i=0;
    switch (set->type){
        case CHAR:
            for(i=0;i<(set)->card;i++){
                if(*(char *)elem == *(char *)((char *)set->elem+i)){
                    return;
                }
            }
            *(char *) ((char *)set->elem+set->card) = *(char *)elem;
            set->card = (set->card)+1;
            // if((set->card)%64==0){
            //         (set->elem)=realloc(elem, (-INITSETSIZE+(set->card)) * (sizeof(char)));
            //     }
            break;

        case INT:
            for(i=0;i<(set)->card;i++){
                if(*(int *)elem == *(int *)((int *)set->elem+i)){
                    return;
                }
            }
            *(int *)((int *)set->elem+set->card)=*(int*)elem;
            set->card = (set->card)+1;
            // if((set->card)%64==0){
            //         (set->elem)=realloc(elem, (-INITSETSIZE+(set->card)) * (sizeof(int)));
            //     }
            break;

        case DOUBLE:
            for(i=0;i<(set)->card;i++){
                if(*(double*)elem==*(double*)((double*)set->elem+i)){
                    return;
                }
            }
            *(double *)((double*)set->elem+set->card)=*(double*)elem;
            set->card = (set->card)+1;
            // if((set->card)%64==0){
            //         (set->elem)=realloc(elem, (INITSETSIZE+(set->card)) * (sizeof(double)));
            //     }
            break;
        default:
        assert(0);
        break;
    }
}

/* remove elem from the set; do nothing if the set does not contain this elem;
resize memory if "too much memory" is used; new = previous-64
e.g. before: mem=192, card=129, after: card=128, mem=128 */
void remElem(void *elem, uset *set) {
    int i=0; char dltc; int dlti; double dltd;  //store the elem to delete from

    switch (set->type){
        case CHAR:
        //char dltc;  //store the elem to delete from
            for(i=0;i<(set)->card;i++){
                if(*(char *)elem == *(char *) ((char *)set->elem+i)){
                    dltc= *(char *)((char *) set-> elem+(set->card-1));
                    *(char *)((char *) set-> elem+(set->card-1)) = *(char *) ((char *)set->elem+i);
                    *(char *)((char *) set->elem+i)=dltc;
                    set->card=set->card-1;
                    return;
                }
                // if((set->card)%64==0){
                //     (set->elem)=realloc(elem, (-INITSETSIZE+(set->card)) * (sizeof(char)));
                // }
            }
        break;

        case INT:
        //int dlti;  //store the elem to delete from
            for(i=0;i<(set)->card;i++){
                if(*(int *)elem == *(int *) ((int *)set->elem+i)){
                    dlti= *(int *)((int *) set->elem+(set->card-1));
                    *(int *)((int *) set->elem+(set->card-1)) = *(int *) ((int *)set->elem+i);
                    *(int *)((int *) set->elem+i)=dlti;
                    set->card=set->card-1;
                    return;
                }
                // if((set->card)%64==0){
                //     (set->elem)=realloc(elem, (-INITSETSIZE+(set->card)) * (sizeof(int)));
                // }
            }
        break;

        case DOUBLE:
        //double dltd;  //store the elem to delete from
            for(i=0;i<(set)->card;i++){
                if(*(double *)elem == *(double *) ((double *)set->elem+i)){
                    dltd= *(double *)((double *) set->elem+(set->card-1));
                    *(double *)((double *) set->elem+(set->card-1)) = *(double *) ((double *)set->elem+i);
                    *(double *)((double *) set->elem+i)=dltd;
                    set->card=set->card-1;
                    return;
                }
                // if((set->card)%64==0){
                //     (set->elem)=realloc(elem, (-INITSETSIZE+(set->card)) * (sizeof(double)));
                // }
            }
        break;

        default:
        assert(0);
        break;
    }
}

