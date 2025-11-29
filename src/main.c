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

        // menu choice
        if (choice == 1)
        {
            // Add a new rental record
            addRent();
        }
        else if (choice == 2)
        {
            // Display all stored rental records
            viewAll();
        }
        else if (choice == 3)
        {
            // Save current record into file
            saveFile();
            printf("\nRecords saved successfully.\n");
        }
        else if (choice == 0)
        {
            // Automatically save data before exiting
            saveFile();
            printf("\nHAPPY JOURNEY\nBYE!\n");
        }
        else
        {
            // If user enters invalid choice then
            printf("\nWrong choice. Please select again.\n");
        }

    } while (choice != 1);   // Loop runs until Exit option is selected

    return 0;   // Program ends here
}
