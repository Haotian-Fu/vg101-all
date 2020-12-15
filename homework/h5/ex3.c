#include "assignment.h"

void ex3(){
    char sentence[10000];
    char word[10000];
    if(fgets(sentence,10000,stdin)!=0){
        if(fgets(word,10000,stdin)!=0){     //read from stdin
            for(int c=0;c<10000;c++){
                if(word[c]=='\n'){
                word[c]='\0';
                break;
            }
        }

        int cnt=0;      //count:=0
        char* ptr=sentence;
        while(1){
            ptr=strstr(ptr,word); //ptr := strstr(ptr, sub)
            if(ptr!=NULL){ //ptr != 0 ?
                cnt++; //count++
            }else{
                break; //return count
            }
            ptr = (char*)((size_t)ptr+1); //ptr++
        }
        printf("The string '%s' occurs %d times\n",word,cnt);
        }
    }
}
//#ifdef JOJ
int main(){
    ex3();
    return 0;
}
//#endif