#include <stdio.h>
#include "vehiclerental.h"

int main() {
    int choice;
 // Showing project title on screen
        printf("\n*******************************\n");
        printf("       --- RENTAL ROADIES ---\n");
        printf("*******************************\n");
   
    while (1) {
        printf("\n1. Add Rental\n");
        printf("2. View All\n");
        printf("3. Save\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        /* EOF safe input for keyboard and sample_input.txt */
        if (scanf("%d", &choice) != 1) {
            printf("\nNo more input. Exiting safely...\n");
            break;
        }

        switch (choice) {
            case 1:
                addRent();     /* Add rental */
                break;

            case 2:
                viewAll();     /* View all rentals */
                break;

            case 3:
                saveData();    /* Save data to file */
                break;

            case 0:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}





       
