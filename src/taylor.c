#include <stdio.h>

float getTerm(int n, int x);

int main () {
    float x;
    float cumRes = 1;
    const float threshold = 0.0000001;
    float term = 0;
    int n = 1;
    printf("enter x : \n");
    scanf("%f", &x);
    do
    {
        term = getTerm(n, x);
        if (term > threshold) {
            cumRes += term;
            n++;
        }
    } while (term > threshold);
    printf("answer is : %f \n", cumRes);
    return 0;
}

float getTerm(int n, int x) {
    float result = 1;
    for (int i = 1; i <= n; i++) {
        result *= (float)x / i;
    }
    return result;
}