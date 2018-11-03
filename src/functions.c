#include <stdio.h>
#include <stdlib.h>

int addition(int, int);
int subtraction(int, int);
int main () {
    int num1 = 0;
    int num2 = 1;
    int choice = 0;
    int result = 0;
    printf("enter two natural numbers: \n");
    scanf("%d %d",&num1, &num2 );
    printf("\n press 1 forr addition 2 for subtraction: \n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            result = addition(num1, num2);
            printf("answer is: %d \n", result);
            break;
        case 2:
            result = subtraction(num1, num2);
            printf("answer is : %d \n", result);
            break;
        default:
            printf("not valid option");
    }



}

int addition(int num1, int num2) {
    return num1 + num2;
}

int subtraction(int num1, int num2) {
    return num1 - num2;
}