#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiclerental.h"

// Array that stores all rental records
struct rentalRec rentArr[RENT_REC];

// Variable to keep track of how many records are stored
int rcount = 0;

// Hourly rental rates based on vehicle type index
float vrates[] = {0, 50, 40, 20, 70, 100, 175, 200, 250, 125};

// Function to display all available vehicles and their rates
void showVehicles()
{
    printf("\n\n---- Available Vehicles ----\n\n");

    printf("1) Bike (Rs 50/hr)\t\t");
    printf("2) Scooty (Rs 40/hr)\n\n");

    printf("3) Cycle (Rs 20/hr)\t\t");
    printf("4) Electric Bike (Rs 70/hr)\n\n");

    printf("5) Mountain Bike (Rs 100/hr)\t");
    printf("6) Maruti Suzuki (Rs 175/hr)\n\n");

    printf("7) Thar (Rs 200/hr)\t\t");
    printf("8) Scorpio (Rs 250/hr)\n\n");

    printf("9) Bullet (Rs 125/hr)\n\n");
}

// Function to return vehicle name based on selected type
const char* vname(int type)
{
    if (type == V_BIKE) return "Bike";
    if (type == V_SCOOTY) return "Scooty";
    if (type == V_CYCLE) return "Cycle";
    if (type == V_EBIKE) return "Electric Bike";
    if (type == V_MBIKE) return "Mountain Bike";
    if (type == V_MSZK) return "Maruti Suzuki";
    if (type == V_THAR) return "Thar";
    if (type == V_SCORP) return "Scorpio";
    if (type == V_BULLET) return "Bullet";

    return "NOT AVAILABLE";   // default case
}

// Function to add a new rental record
void addRent()
{
    // Check if memory limit is reached
    if (rcount >= RENT_REC)
    {
        printf("Storage full. Cannot add more records.\n");
        return;
    }

    struct rentalRec r;   // temporary structure to store input

    // License ID validation loop
    do
    {
        printf("\nEnter license ID (5 digits only): ");
        scanf("%d", &r.rid);

        if (r.rid < 10000 || r.rid > 99999)
        {
            printf("Invalid license ID! Try again.\n");
        }

    } while (r.rid < 10000 || r.rid > 99999);

    // Taking customer name
    printf("Enter Customer Name: ");
    scanf(" %59[^\n]", r.cname);

    // Show vehicle list before selection
    showVehicles();

    // Taking vehicle choice
    printf("Choose vehicle: ");
    scanf("%d", &r.vtype);

    // Validate vehicle choice
    if (r.vtype < 1 || r.vtype > 9)
    {
        printf("Invalid vehicle selection!\n");
        return;
    }

    // Taking rental hours
    printf("Hours taken: ");
    scanf("%d", &r.hrs);

    // Calculating total cost
    r.cost = r.hrs * vrates[r.vtype];

    // Storing the record into main array
    rentArr[rcount] = r;
    rcount++;

    printf("Rental added successfully. Total cost: Rs %.2f\n", r.cost);
}

// Function to display all rental records
void viewAll()
{
    // Check if there are no records
    if (rcount == 0)
    {
        printf("No records found.\n");
        return;
    }

    // Display table header
    printf("\nID           | Customer                | Vehicle              | Hours   | Cost      |\n");
    printf("-------------------------------------------------------------------------------------\n");

    // Loop to print each record
    for (int i = 0; i < rcount; i++)
    {
        printf("%-12d | %-22s | %-20s | %-7d | Rs %-8.2f |\n",
               rentArr[i].rid,
               rentArr[i].cname,
               vname(rentArr[i].vtype),
               rentArr[i].hrs,
               rentArr[i].cost);
    }
}

// Function to save all records to binary file
void saveFile()
{
    FILE *fp = fopen("vehRent.dat", "wb");

    if (fp == NULL)
    {
        printf("Error while saving file.\n");
        return;
    }

    // Writing complete array into file
    fwrite(rentArr, sizeof(struct rentalRec), rcount, fp);
    fclose(fp);
}

// Function to load records from binary file
void loadFile()
{
    FILE *fp = fopen("vehRent.dat", "rb");

    if (fp != NULL)      // if any error in opening by function fopen it return null ... 
    {
        // Reading all records from file into array
        rcount = fread(rentArr, sizeof(struct rentalRec), RENT_REC, fp);
        fclose(fp);
    }
}
