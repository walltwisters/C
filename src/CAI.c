#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
void subtraction();
void addition();
int checkAnswer(int, int, int, int);
int menu(int *);
int submenu(int *);
int generateNumber();
void test();
void practice();
int main(){
    int choice, type, ans, iterations, i;
    time_t t;
    srand( ( unsigned ) time(&t));
    do {
        choice = menu(&choice);
        printf("submenu\n");
        type = submenu(&type);
        iterations = choice == 1 ? 15 : 10;
        printf("iterations %d\n", iterations);
        switch (type){
            case 1:
                for( i = 0; i < iterations; i++){
                    addition();
                }
                break;
            case 2:
                for( i = 0; i < iterations; i++){
                    subtraction();
                }
                break;
            case 3:
                for( i = 0; i < iterations; i++){
                    if ( generateNumber() < 50){
                        addition();
                    } else {
                        subtraction();
                    }
                }
                break;
        }
    } while (choice < 3);
        
    return 0;
}

int menu( int *choice){
    printf("make a choice:\n1.\ttest\n2.\tpractice\n3.\tquit\n");
    scanf("%d", &choice);
    printf("\nchoice:%d", choice);
    return choice;
}

int submenu(int * choice){
    printf("make a choice:\n1.\taddition\n2.\tsubtraction\n3.\tmixed\n");
    scanf("%d", &choice);
    printf("\nchoice:%d\n", choice);
    return choice;
}

void addition(){
    int x, y, ans;
    x = generateNumber();
    y = generateNumber();
    do{
        printf("\nwhat is %d + %d : \t", x, y);
        scanf("%d", &ans);
    } while(!checkAnswer(x, y, ans, 0));
    
}
void subtraction(){
    int x, y, ans;
    x = generateNumber();
    y = generateNumber();
    do{
        if(x > y){
            printf("\nwhat is %d - %d : \t", x, y);
        } else {
            printf("\nwhat is %d - %d : \t", y, x);
        }
        scanf("%d", &ans);
    } while(!checkAnswer(x, y, ans, 1));
}

int checkAnswer(int x, int y, int ans, int subtraction){
    int correct;
    if(!subtraction){
        correct = (x + y) == ans;
    } else {
        if( x > y){
            correct = ( x - y ) == ans;
        } else {
            correct = ( y - x ) == ans;
        }
    }
    return correct;
}

int generateNumber(){
    return rand() % 101;
}
