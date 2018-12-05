#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CAIv2.h"

int main(){
    int choice;
    time_t t;
    srand( ( unsigned ) time(&t));
    do{
        char* choices[] = {"test", "practice", "quit", 0};
        choice = menu(choices);
        switch(choice){
            case 1:
                test();
                break;
            case 2:
                practice();
                break;
            case 3:
            default :
                break;
        } 
    } while ( choice == 1 || choice == 2);
    
    return 0;
}

int menu(char** ppChoices){
    int num = 0;
    int menuVal = 0;
    do{
        printf("your can choose:\n");
        num = 0;
        char** ppChoice = ppChoices;
        while (*ppChoice) {
            printf("%d\t%s\n", ++num, *ppChoice);
            ppChoice++;
        }
        menuVal = getNumberFromStdin();
    } while(menuVal < 1 || menuVal > num);
    
    return menuVal;
}

void practice(){
    int choice;
    const int addition = 1;
    const int subtraction = 2;
    const int mixed = 3;
    const int numberOfQuestions = 4;
    printf("\nnow you can choose to do practices on:\n");
    choice = selectTypeOfQuestions();
    switch(choice){
        case 1:
            createSession(0, numberOfQuestions, addition);
            break;
        case 2:
            createSession(0, numberOfQuestions, subtraction);
            break;
        case 3:
        default :
            createSession(0, numberOfQuestions, mixed);
            break;
        case 4:
            return;
    }
}

void test(){
    int choice;
    const int numberOfQuestions = 2;
    int correctAnswers = 0;
    const int addition = 1;
    const int subtraction = 2;
    const int mixed = 3;
    int i;
    struct TestAnalysis analysis[numberOfQuestions];
    printf("\nnow you can choose to do practices on:\n");
    choice = selectTypeOfQuestions();
    switch(choice){
        case 1:
            createSession(analysis, numberOfQuestions, addition);
            break;
        case 2:
            createSession(analysis, numberOfQuestions, subtraction);
            break;
        case 3:
        default :
            createSession(analysis, numberOfQuestions, mixed);
            break;
        case 4:
            return;
    }
    printf("\n  Question\tCorrect Answer\tYour Answer\n");
    for( i = 0; i < numberOfQuestions; i++){
        printf("%d.%s\t%d\t%d\n", i + 1, analysis[i].question, analysis[i].correctAnswer, analysis[i].studentAnswer);
        correctAnswers += analysis[i].correctAnswer == analysis[i].studentAnswer ? 1 : 0;
    }
    printf("\npercentage score is : %0.1f %%\n\n\n", (float) correctAnswers / numberOfQuestions * 100);
}

int selectTypeOfQuestions(){
    char* choices[] = {"addition", "subtraction", "mixed", "back", 0};
    return menu(choices);
}

void createSession(struct TestAnalysis *pAnalysis, int numberOfQuestions, int sessionType){
    int i;
    for( i = 0; i < numberOfQuestions; i++){
        switch(sessionType){
            case 1:
                generateQuestionAddition(pAnalysis ? pAnalysis + i : 0);
                break;
            case 2:
                generateQuestionSubtraction(pAnalysis ? pAnalysis + i : 0);
                break;
            case 3:
            default:
                if(generateNumber() % 2){
                    generateQuestionAddition(pAnalysis ? pAnalysis + i : 0);
                } else {
                    generateQuestionSubtraction(pAnalysis ? pAnalysis + i : 0);
                }
                break;
        }
    }
}

void generateQuestionAddition(struct TestAnalysis *pAnalysis){
    int x, y;
    const int addition = 0;
    getTwoNumbers(&x, &y, addition);
    if (pAnalysis) {
        // Just one shot, doing test
        sprintf( pAnalysis->question, "%d + %d", x, y);
        pAnalysis->correctAnswer = x + y;
        printf("\nwhat is %s : \t", pAnalysis->question);
        pAnalysis->studentAnswer = getNumberFromStdin();
    } else {
        // Go on until correct, doing practice
        do{
            printf("\nwhat is %d + %d : \t", x, y);
        } while(!assertAnswer(x + y, getNumberFromStdin()));
    }

}

void generateQuestionSubtraction(struct TestAnalysis *pAnalysis){
    int x, y;
    const int subtraction = 1;
    getTwoNumbers(&x, &y, subtraction);
    if (pAnalysis) {
        sprintf( pAnalysis->question, "%d - %d", x, y);
        pAnalysis->correctAnswer = x - y;
        printf("\nwhat is %s : \t", pAnalysis->question);
        pAnalysis->studentAnswer = getNumberFromStdin();
    } else {
        // Go on until correct, doing practice
        do{
            printf("\nwhat is %d - %d : \t", x, y);
        } while(!assertAnswer(x - y, getNumberFromStdin()));
    }

}

int assertAnswer(int expected, int provided) {
    if (expected == provided) {
        printf("Bravo. Correct answer\n");
        return 1;
    } else {
        printf("Sorry. Wrong answer. Try again\n");
        return 0;
    }
}

void getTwoNumbers(int *pX, int *pY, int largestFirst) {
    *pX = generateNumber();
    *pY = generateNumber();
    if (largestFirst && *pX < *pY) {
        int temp = *pX;
        *pX = *pY;
        *pY = temp;
    }
}

int getNumberFromStdin() {
    int ans;
    char buffer[80];
    char *line = fgets(buffer, 80, stdin);
    sscanf(line, "%d", &ans);
    return ans;
}

int generateNumber(){
    return rand() % 101;
}



