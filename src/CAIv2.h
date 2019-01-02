struct TestAnalysis {
    char question[80];
    int correctAnswer;
    int studentAnswer;
};
int menu(char** ppChoices);
int selectTypeOfQuestions();
void practice();
void test();
void createSession(struct TestAnalysis *pAnalysis, int numberOfQuestions, int sessionType);
void generateQuestionAddition(struct TestAnalysis *pAnalysis);
void generateQuestionSubtraction(struct TestAnalysis *pAnalysis);
int generateNumber();
void getTwoNumbers(int *pX, int *pY, int);
int getNumberFromStdin();
int assertAnswer(int expected, int provided);
char* correctAnswer();
char* inCorrectAnswer();
char* generateAnswer();