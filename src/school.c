#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int main(){
    int x, y, ans, correctAnswers;
    _Bool xIsGreaterThanY, correct;
    time_t t;

    correctAnswers = 0;
    srand((unsigned) time(&t));
   
    do{
        correct = false;
        x = rand() % 100;
        y = rand() % 100;
        while(!correct) {
            if ( x > y ) {
                xIsGreaterThanY = true;
                printf("calculate %d - %d \n", x, y);
            } else {
                xIsGreaterThanY = false;
                printf("calculate %d - %d \n", y, x);
            }
            scanf("%d", &ans);
            printf("received answer : %d\n", ans);
            if (xIsGreaterThanY) {
                correct =  ans == x - y;
            } else {
                correct = ans == y - x;
            }
            if(correct) {
                printf("congrats answer correct\n");
                correctAnswers++;
            } else {
                printf("wrong! try again\n");
            };
        };
    } while (correctAnswers < 10 );

    return 0;
}