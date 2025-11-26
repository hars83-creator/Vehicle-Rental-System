#include <stdio.h>
#include "vehiclerental.h"
#include "utils.h"

int main() {
    int ch;
    loadFile();
 // user interface 
    do {
        printf("\n*******************************\n");
        printf("   --- RENTAL ROADIES --- ");                       // name for the system 
        printf("\n*******************************\n");
// menu for selection what you want 
        printf("1. Add Rental\n");
        printf("2. View All\n");
        printf("3. Save\n");
        printf("0. Exit\n");
        printf(" Choice: ");

        scanf("%d", &ch);
        
         clerscrn(); // for clear screen 

        // for selction via switch cases
        switch(ch) {
            case 1: addRent(); break;
            case 2: viewAll(); break;
            case 3: saveFile(); break;
            case 0: saveFile(); printf("HAPPY JOURNEY\n BYE! \n"); break;
            default: printf("Wrong choice.\n");
        }


    } while(ch != 0);

    return 0;
}
