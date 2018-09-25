#include <stdio.h>
#include <string.h>

int isPalendrome(char* word, int casesens, int punctuation){
//        for(int i = 1; i<argc; i++) {
        int p=0;
        char nospace[400];

        for(int j = 0; j<=strlen(word);j++){
            nospace[j]=word[j];
        }
/*
        for(int j = 0; j<=strlen(nospace);j++){
            if(nospace[j]!=' '||nospace[j]=='\0'){
                nospace[p]=nospace[j];
            }
        }
*/
        if(punctuation){
            for(int j = 0; j<=strlen(nospace);j++){
                if((nospace[j]>='a'&&nospace[j]<='z')||(nospace[j] >='A'&&nospace[j]<='Z') || (nospace[j]=='\0')){
                    nospace[p]=nospace[j];
                    p++;
                }     
            }
        }

        if(casesens){
            for(int j = 0; j<=strlen(nospace);j++){
                if((nospace[j]>='A'&&nospace[j]<='Z'))
                    nospace[j]=nospace[j] - ('A'-'a');
                else
                    nospace[j]=nospace[j];
            }
        }

    int len = strlen(nospace)-1;
        for(int i = 0; i < len; i++){
            if(nospace[i] != nospace[len-i])
               return 0;
            }
            return 1;
}


int main(int argc, char * argv[]) {
    int k=1;
    int casesens=1, punctuation=1, welcome=1;
    int startingpoint=-1;

    for(int i = 1; i<argc; i++) {
        if(argv[i][0]=='-'){
            startingpoint=i;
            if((argv[i][1]=='c')||(argv[i][2]=='c')||(argv[i][3]=='c')){
                casesens=0;
            }
            if((argv[i][1]=='p')||(argv[i][2]=='p')||(argv[i][3]=='p')){
                punctuation=0;
            }
            if((argv[i][1]=='q')||(argv[i][2]=='q')||(argv[i][3]=='q')){
                welcome=0;
            }
            
            if((argv[i][1]!='c')||(argv[i][2]!='c')||(argv[i][3]!='c')||(argv[i][1]!='p')||(argv[i][2]!='p')||(argv[i][3]!='p')||(argv[i][1]!='q')||(argv[i][2]!='q')||(argv[i][3]!='q')){
                printf("That was not part of the available options. Use p to disable punction. Use c to enable extra characters. And use q to disable the diplay messages.\n");
            }
            
        }    
    }

    if(welcome){

    printf("Initializing...\n");
    printf(".....\n");
    printf("Use -p to disable punction. Use -c to enable extra characters. And use -q to disable the diplay messages.\n");
    printf("Welcome to this not so glorious palindrome checker.\n");
    printf("You have several options for this program.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    }

    for(int i = 1; i<argc; i++) {
        if(i!=startingpoint){
        int c = isPalendrome(argv[i], casesens, punctuation);
        if(c==1)
            printf("%s is a palindrome\n", argv[i]);
        else
            printf("%s is not a palindrome\n", argv[i]);
        k++;
        }
    }
    if(welcome){
        printf("\n");
        printf("\n");
        printf("\n");
        printf("Thanks for making me do something.\n");
    }
    return 0;
}