#include <stdio.h>
#include <string.h>
 
int main()
{
    char *str1 = "A";
    char *str2 = "A";
    char *str3 = "!";
 
    printf("\nstr1 = %s\n", str1);
    printf("\nstr2 = %s\n", str2);
    printf("\nstr3 = %s\n", str3);
    printf("\nstrcmp(str1, str2) = %d\n", strcmp(str1, str2));
    printf("\nstrcmp(str1, str3) = %d\n", strcmp(str1, str3));
    printf("\nstrcmp(str3, str1) = %d\n", strcmp(str3, str1));
 
    if ( strcmp(str1, str2) == 0 )
        printf("\nLetter A is equal to letter A\n");
    if ( strcmp(str1, str3) > 0 )
        printf("Letter A is greater than character !\n");
    if ( strcmp(str3, str1) < 0 )
        printf("Character ! is less than letter A\n");
    return 0;
} // end main