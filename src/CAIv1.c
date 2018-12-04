#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct TestAnalysis {
    char question[80];
    int correctAnswer;
    int studentAnswer;
};
char menu();
char submenu();
void practice();
void test();
void practiceAddition();
void practiceMixed();
void practiceSubtraction();
void testAdditions(struct TestAnalysis *, int);
void testMixed(struct TestAnalysis *, int);
void testSubtractions(struct TestAnalysis *, int);
void testAddition(struct TestAnalysis *);
void testSubtraction(struct TestAnalysis *);
void addition();
void subtraction();
int generateNumber();
int checkAnswer(int, int, int, int);


int main(){
    char choice;
    time_t t;
    srand( ( unsigned ) time(&t));
    do{
        choice = menu();
        switch(choice){
            case '1':
                test();
                break;
            case '2':
                practice();
                break;
            case '3':
            default :
                break;
        } 
    } while ( choice == '1' || choice == '2');
    
    return 0;
}

char menu(){
    char buffer[80];
    char *line;
    do{
        printf("your can choose:\n");
        printf("1.\ttest\n2.\tpractice\n3.\tquit\n");
        line = fgets(buffer, 80, stdin);
    } while(*line < '1' || *line > '3');
    
    return *line;
}

char submenu(){
    char buffer[80];
    char *line;
    do{
        printf("\nnow you can choose to do practices on:\n");
        printf("1.\taddition\n2.\tsubtraction\n3.\tmixed\n");
        line = fgets(buffer, 80, stdin);
    } while(*line < '1' || *line > '3');
    return *line;
}

void practice(){
    char choice;
    printf("\npractice\n");
    choice = submenu();
    switch(choice){
        case '1':
            practiceAddition();
            break;
        case '2':
            practiceSubtraction();
            break;
        case '3':
        default :
            practiceMixed();
            break;
    }
}

void test(){
    char choice;
    const int numberOfQuestions = 2;
    int i;
    int correctAnswers = 0;
    struct TestAnalysis analysis[numberOfQuestions];
    printf("\ntest\n");
    choice = submenu();
    switch(choice){
        case '1':
            testAdditions(analysis, numberOfQuestions);
            break;
        case '2':
            testSubtractions(analysis, numberOfQuestions);
            break;
        case '3':
        default :
            testMixed(analysis, numberOfQuestions);
            break;
    }
    printf("\n  \tQuestion\tCorrect Answer\tYour Answer\n");
    for( i = 0; i < numberOfQuestions; i++){
        printf("%d.\t%s\t\t%d\t\t%d\n", i + 1, analysis[i].question, analysis[i].correctAnswer, analysis[i].studentAnswer);
        correctAnswers += analysis[i].correctAnswer == analysis[i].studentAnswer ? 1 : 0;
    }
    printf("\nprecentage score is : %f1\n", (float) correctAnswers / numberOfQuestions);
}

void testAdditions(struct TestAnalysis *analysis, int numberOfQuestions){
    int i;
    for(i = 0; i < numberOfQuestions ; i++){
        testAddition(&analysis[i]);
    }
}

void testSubtractions(struct TestAnalysis *analysis, int numberOfQuestions){
    int i;
    for(i = 0; i < numberOfQuestions; i++){
        testSubtraction(&analysis[i]);
    }
}
void testMixed(struct TestAnalysis *analysis, int numberOfQuestions){
    int i;
    for(i = 0; i < numberOfQuestions; i++){
        if(generateNumber() < 50){
            testAddition(&analysis[i]);
        } else {
            testSubtraction(&analysis[i]);
        }
    }
}

void practiceMixed(){
    int i;
    for( i = 0; i < 10; i++){
        if ( generateNumber() < 50){
            addition();
        } else {
            subtraction();
        }
    }
}

void practiceSubtraction(){
    int i;
    for(i = 0; i < 10; i++){
        subtraction();
    }
}

void practiceAddition(){
    int i;
    for(i = 0; i < 10; i++){
        addition();
    }
}

void testAddition(struct TestAnalysis *analysis){
    int x, y, ans;
    x = generateNumber();
    y = generateNumber();
    sprintf( analysis->question, "%d + %d", x, y);
    analysis->correctAnswer = x + y;
    printf("\nwhat is %s : \t", analysis->question);
    scanf("%d", &ans);
    analysis->studentAnswer = ans;
}

void testSubtraction( struct TestAnalysis *analysis){
    int x, y, ans;
    x = generateNumber();
    y = generateNumber();
    if( x < y){
        sprintf( analysis->question, "%d - %d", y, x);
         analysis->correctAnswer = y - x;
    } else {
        sprintf(analysis->question, "%d - %d", x, y);
        analysis->correctAnswer = x - y;
    }
    printf("\nwhat is %s : \t", analysis->question);
    scanf("%d", &ans);
    analysis->studentAnswer = ans;
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
    if(correct){
        printf("correct answer\n");
    } else {
        printf("wrong answer\n");
    }
    return correct;
}

int generateNumber(){
    return rand() % 101;
}
