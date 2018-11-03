#include <stdio.h>
#include <stdlib.h>
int main() {
    int iResponse = 0;
    while ( iResponse != 4){
        printf("\n1.listDirectory\t 2.listDirectoryDeep\t 3.switchToParentDirectory\t 4.exit\n");
        scanf("%d", &iResponse);
        switch(iResponse){
            case 1:
                system("clear");
                system("li");
                break;
            case 2:
                system("clear");
                system("li -la");
                break;
            case 3:
                system("clear");
                system("cd ..");
                break;
            case 4:
                printf("good bye!\n");
                break;
            default : 
                printf("invalid option. Try again!\n");
        }
   
    }
    system("clear");

    return 0;
}