#include <stdio.h>
 
int main()
{
    FILE *pWrite;
    char fName[20];
    char lName[20];
    char game[15];
    int score;
    pWrite = fopen("file1.dat", "a");
 
    if ( pWrite == NULL ) {
        printf("\nFile not opened\n");
        return 1; }
    else {
        printf("\nEnter first name, last name, game name, and game score\n\n");
        printf("Enter data separated by spaces: ");
        //store data entered by the user into variables
        scanf("%s%s%s%d", fName, lName, game, &score);
        //write variable contents separated by tabs
        fprintf(pWrite, "%s\t%s\t%s\t%d\n", fName, lName, game, score);
        fclose(pWrite);
    } //end if
    return 0;
} //end main