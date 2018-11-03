#include <stdio.h>
#define MAX  30
int main ( )
{
    int size;
    int row, column;
    //read in a valid size
    do
    {
        printf("Enter the number of rows in pyramid (1--%d):", MAX);
        scanf("%d", & size);}
        while (size < 1 || size > MAX);
        //print the pyramid
        row = 1;
        while (row <= size) // print a line
        {
            // print spaces
            for (column =1; column <= size -row; column++)
                printf(" ");
            // print stars
            for (column =1; column <= 2*row -1; column ++)
                printf("*");
            // terminate the line
            printf("\n");
            row = row + 1;
        }
        return 0;
    }