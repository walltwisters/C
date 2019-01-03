#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "CAIv2.h"

int main(){
    int choice;
    time_t t;
    srand( ( unsigned ) time(&t));
    do{
        char* choices[] = {"test", "practice", "results","best result", "quit", 0};
        choice = menu(choices);
        switch(choice){
            case 1:
                test();
                break;
            case 2:
                practice();
                break;
            case 3:
                displayPreviousResults();
                break;
            case 4:
                displayBestResult();
                break;
            case 5:
            default :
                break;
        } 
    } while ( choice == 1 || choice == 2 || choice == 3 || choice == 4);
    
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

void displayPreviousResults() {
    FILE *pStream;
    char name[80] = {"\0"};
    char sessionType[80]= {"\0"};
    float result;
    pStream = fopen("results.dat", "r");
    printf("\n\nsessiontype\tname\tresult\n\n");
    if( pStream == NULL) {

    } else {
        fscanf(pStream, "%s%s%f",sessionType, name, &result);
        while( !feof(pStream) ){
            printf("%s\t%s\t%f\n", sessionType, name, result);
            fscanf(pStream, "%s%s%f",sessionType, name, &result);
        }
        printf("\n\n");
    }
}

void displayBestResult() {
    FILE *pStream;
    char name[80] = {"\0"};
    float highestResult = 0;
    char champion[80] = {"\0"};
    float result;
    pStream = fopen("results.dat", "r");
    printf("\n\n\n");
    if( pStream == NULL) {

    } else {
        fscanf(pStream, "%s%f", name, &result);
        while( !feof(pStream) ){
            if( result > highestResult){
                highestResult = result;
                strcpy(champion, name);
            }
            //highestResult= result > highestResult ? result : highestResult;
            fscanf(pStream, "%s%f",name, &result);
        }
        printf("\nhighest result so far is : %f\tby %s\n\n", highestResult, champion);
    }
}

void practice(){
    int choice;
    const int addition = 1;
    const int subtraction = 2;
    const int mixed = 3;
    const int numberOfQuestions = 15;
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
    const int numberOfQuestions = 10;
    int correctAnswers = 0;
    const int addition = 1;
    const int subtraction = 2;
    const int mixed = 3;
    int i;
    float result;
    char name[80] = {'\0'};
    struct TestAnalysis analysis[numberOfQuestions];
    printf("\nnow you can choose to do test on:\n");
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
    printf("\npercentage score is : %0.1f %%\n\n\n", result = (float) correctAnswers / numberOfQuestions * 100);
    printf("add your name: ");
    scanf("%s", name);
    saveToFile(result, name, choice);
}

void saveToFile(float result, char *pName, int choice){
    FILE *pWrite;
    char *pType;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);
    switch(choice) {
        case 1:
            pType = "addition";
            break;
        case 2:
            pType = "subtraction";
            break;
        case 3:
            pType = "mixed";
            break;
    }
    pWrite = fopen("results.dat", "a");
    if ( pWrite == NULL ) {
        printf("\nFile not opened\n");
        //return 1; 
    }
    else {
        fprintf(pWrite, "%s\t%s\t%f\t%s\n", pType, pName, result, s);
        fclose(pWrite);
    } 
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
        printf("%s", correctAnswer());
        return 1;
    } else {
        printf("%s", inCorrectAnswer());
        return 0;
    }
}

char* correctAnswer() {
    char* answers[] = {"Bravo!", "Correct Answer!", "Good!", "Very Good!", "Excellent"};
    return generateAnswer(answers);
    
}

char* generateAnswer(char** answers){
    int random;
    random = generateNumber() % 5;
    return answers[random];
}

char* inCorrectAnswer() {
    char* answers[] = 
        {
            "Wrong! Try again!",
            "Learnig takes practice, give it another go", 
            "not exactly but try again",
             "wrong answer, but dont give up", 
             "try again please!"
        };
    return generateAnswer(answers);
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



