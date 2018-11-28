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
        term = getTerm(n, x);
        if (fabs(term) > threshold) {
            cumRes += term;
            printf("\n\n\ncumres is now %f\n\n\n", cumRes);
            n++;
        }
    } while (fabs(term) > threshold);
    printf("answer is : %f \n", cumRes);
    return 0;
}

float getTerm(int n, int x) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        printf(" calculating term nr %d\t and iteration nr %d\t %f\n", n, i,result);
        result *= (double)x / i;
    }
    printf("\n\nexit second inner loop result is now %f\n\n", fabs(result));
    return result;
}