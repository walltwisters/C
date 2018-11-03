#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int indexOf(char[], int, char);

int main() {
    int i;
    int iFound = 0;
    int len;
    char cSearch[2];
    char str[50];
    
    printf("please, enter arbitrary string \n");
    scanf("%s", str);
    len = strlen(str);
    printf("searchstring: %s , string carachter amount : %d \n", str, len);
    
    printf("\nenter a charchater to search for: \n");
    scanf("%s", cSearch);
    printf("character is : '%s'", cSearch);
    
    iFound = indexOf(str, len, cSearch[0]);
    if( iFound > -1) {
        printf("carachter found at position %d \n", iFound);
    } else {
        printf("name dosent contain charachter \n");
    }
    
    
    return 0;


}

int indexOf(char string[50], int length, char searchValue) {
    int iFound = -1;
    int index;
    for(index = 0; index < length; index++){
        if( string[index] == searchValue){
            iFound = index;
            break;
        }
    }

    return iFound;
}