#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float getTerm(int n, int x);

int main () {
    float x;
    double cumRes = 1;
    const float threshold = 0.0000001;
    double term = 0;
    int n = 1;
    printf("enter x : \n");
    scanf("%f", &x);
    do
    {
        term = getTerm(n, fabs(x));
        if (term > threshold) {
            cumRes += term;
            n++;
        }
    } while (term > threshold);
    printf("answer is : %f \n", x < 0 ? 1/cumRes : cumRes);
    return 0;
}

float getTerm(int n, int x) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= (double)x / i;
    }
    return result;
}