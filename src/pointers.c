#include <stdio.h>
 
int main()
{
    char *strNames[5] = {0};
    char answer[80] = {0};
    int x;
    strNames[0] = "Michael";
    strNames[1] = "Sheila";
    strNames[2] = "Spencer";
    strNames[3] = "Hunter";
    strNames[4] = "Kenya";
 
    printf("\nNames in pointer array of type char:\n\n");
 
    for ( x = 0; x < 5; x++ )
         printf("%s\n", strNames[x]);
    return 0;
} //end main