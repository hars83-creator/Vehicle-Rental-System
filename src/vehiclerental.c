#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiclerental.h"

struct rentalRec rentArr[RENT_REC];
int rcount = 0;
// rates of  vehicles 
float vrates[] = {0,50,40,20,70,100,175,200,250,125};

// how vehicle list show on terminal ....

void showVehicles()
{
    printf("\n\n---- Vehicles ----\n\n");
    printf("1) Bike (50/hr)\t");           printf("\t\t2) Scooty (40/hr)\n\n");
    printf("3) Cycle (20/hr)\t");           printf("\t4) Electric Bike (70/hr)\n\n");
    printf("5) Mountain Bike (100/hr)");     printf("\t6) Maruti Suzuki (175/hr)\n\n");
    printf("7) Thar (200/hr)\t");            printf("\t8) Scorpio (250/hr)\n\n");
    printf("9) Bullet (125/hr)\n\n");
}

// returning vehicle name ******************

const char* vname(int t) {
    switch(t) {
        case V_BIKE: return "Bike";
        case V_SCOOTY: return "Scooty";
        case V_CYCLE: return "Cycle";
        case V_EBIKE: return "Electric Bike";
        case V_MBIKE: return "Mountain Bike";
        case V_MSZK: return "Maruti Suzuki";
        case V_THAR: return "Thar";
        case V_SCORP: return "Scorpio";
        case V_BULLET: return "Bullet";
        default: return "NOT AVAILABLE";
    }
}

// function for saving file **********

void addRent() {
    if(rcount >= RENT_REC) {
        printf("Storage full.\n");
        return;
    }
// structure for rental record ***********
    
    struct rentalRec r;
    do {
        printf("\nEnter license ID (5 digits only): ");
        scanf("%d", &r.rid);
        if (r.rid < 10000 || r.rid > 99999) {
            printf("Invalid license ID! Please enter valid license id.\n");
        }
    } while (r.rid < 10000 || r.rid > 99999);

    printf("Enter Customer Name: ");
    scanf(" %59[^\n]", r.cname);
    
// function for showing vehice list **********
    showVehicles();
    printf("Choose vehicle: ");
    scanf("%d", &r.vtype);


// check for you enter the valid input *********
    if(r.vtype < 1 || r.vtype > 9) {
        printf("Invalid vehicle!\n");
        return;
    }

    printf("Hours taken: ");
    scanf("%d", &r.hrs);

    r.cost = r.hrs * vrates[r.vtype];

    rentArr[rcount++] = r;

    printf("Added. Total: Rs %.2f\n", r.cost);
}

// function for viewing all records *********

void viewAll()
 {
    if(rcount == 0) {
    printf("No records.\n");
    return;
}

printf("\nID           | Customer                | Vehicle              | Hours   | Cost      |\n");  // header for all record 
printf("-------------------------------------------------------------------------------------\n");
for (int i = 0; i < rcount; i++) {
    printf("%-12d | %-22s | %-20s | %-7d | ₹ %-8.2f |\n",    // for proper record mangement (deign for records).
        rentArr[i].rid,    // for license id 
        rentArr[i].cname,   // for name 
        vname(rentArr[i].vtype),   // for vehicle type
        rentArr[i].hrs,    // for rented hours 
        rentArr[i].cost       // for cost 
    );


    }
}

// for saving file 

void saveFile() {
    FILE *fp = fopen("vehRent.dat","wb");
    if(!fp) {
        printf("File not saved\n");
        return;
    }
    fwrite(rentArr, sizeof(struct rentalRec), rcount, fp);
    fclose(fp);
}

