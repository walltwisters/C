#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int correctAnswers = 0;
    int answer;
    int const numberOfQuestions = 2;
    int correct = 0;
    int a, b;
    time_t t;
    srand((unsigned) time(&t));
    while(correctAnswers < numberOfQuestions){
        a = rand() % 101;
        b = rand() % 101;
        do{
            if(a < b) {
                printf("how much is %d - %d : \t", b, a);
                scanf("%d", &answer);
                correct = answer == b - a;
            } else {
                printf("how much is %d - %d : \t", a, b);
                scanf("%d", &answer);
                correct = answer == a - b;
            }
            if(correct){
                printf("\ncorrectanswer!!\n");
            } else {
                printf("\nwrong, try again!\n");
            }
        } while(!correct);
        correctAnswers++;
    }
    printf("\ncongrats!!\nyou have successfully answered %d questions\n", numberOfQuestions);
    return 0;
}
