#include <stdio.h>
#include "vehiclerental.h"
#include "utils.h"

int main()
{
    int choice;   // variable to store user menu choice

    // Load previously saved rental data from file (if any)
    loadFile();

    // Main program loop runs until user chooses Exit
    do
    {
        // Showing project title on screen
        printf("\n*******************************\n");
        printf("       --- RENTAL ROADIES ---\n");
        printf("*******************************\n");

        // Menu options
        printf("1. Add Rental\n");
        printf("2. View All\n");
        printf("3. Save\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clearing screen for best user interface
        clerscrn();

       while (1) {
    printf("\n1. Add Rental\n");
    printf("2. View All\n");
    printf("3. Save\n");
    printf("0. Exit\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("\nInput finished. Auto exit.\n");
        break;
    }

    switch (choice) {
        case 1:
            addRental();
            break;
        case 2:
            viewAll();
            break;
        case 3:
            saveData();
            break;
        case 0:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
    }
}

    return 0;   // Program ends here
}
