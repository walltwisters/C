#include <stdio.h>
main() {
    int i,j, k;
    k = 0;
    for( i = 1; i<= 5; i++) {
        for(j=i;j<=5;j++){
            printf("* ");
            k++;
        }
    }
    printf("\n%d\n", k);
    printf("%d\n", 3 * 4/5 );
    return 0;
}