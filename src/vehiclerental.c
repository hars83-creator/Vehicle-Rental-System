
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rental.h"

/* ---------- GLOBAL DATA ---------- */
struct rentalRec rentArr[RENT_REC];
int rcount = 0;
float vrates[10] = {0, 50, 40, 20, 70, 100, 175, 200, 250, 125};

/* ---------- VEHICLE LIST ---------- */
void showVehicles()
{
    printf("\n---- Vehicles ----\n");
    printf("1) Bike (50/hr)\t\t2) Scooty (40/hr)\n");
    printf("3) Cycle (20/hr)\t\t4) Electric Bike (70/hr)\n");
    printf("5) Mountain Bike (100/hr)\t6) Maruti Suzuki (175/hr)\n");
    printf("7) Thar (200/hr)\t\t8) Scorpio (250/hr)\n");
    printf("9) Bullet (125/hr)\n");
}

const char* vname(int t)
{
    switch(t) {
        case V_BIKE: return "Bike";
        case V_SCOOTY: return "Scooty";
        case V_CYCLE: return "Cycle";
        case V_EBIKE: return "E-Bike";
        case V_MBIKE: return "M-Bike";
        case V_MSZK: return "Maruti";
        case V_THAR: return "Thar";
        case V_SCORP: return "Scorpio";
        case V_BULLET: return "Bullet";
        default: return "N/A";
    }
}

/* ---------- LOGIN ---------- */
int login()
{
    char pass[20];
    printf("\n=== ADMIN LOGIN ===\n");
    printf("Enter Password: ");
    scanf("%19s", pass);

    if(strcmp(pass, ADMIN_PASS) == 0) {
        printf("Login Successful!\n");
        return 1;
    }
    printf("Wrong Password!\n");
    return 0;
}

/* ---------- ADD RENT ---------- */
void addRent()
{
    if(rcount >= RENT_REC) return;
    struct rentalRec r;

    do {
        printf("Enter 5-digit License ID: ");
        scanf("%d", &r.rid);
    } while(r.rid < 10000 || r.rid > 99999);

    printf("Enter Customer Name: ");
    scanf(" %59[^\n]", r.cname);

    showVehicles();
    scanf("%d", &r.vtype);
    printf("Enter Hours: ");
    scanf("%d", &r.hrs);

    r.cost = r.hrs * vrates[r.vtype];

    time_t now;
    struct tm *t;
    time(&now);
    t = localtime(&now);
    strftime(r.date, sizeof(r.date), "%d-%m-%Y", t);
    strftime(r.time, sizeof(r.time), "%H:%M:%S", t);

    rentArr[rcount++] = r;
    printf("Rental Added! Cost = ₹%.2f\n", r.cost);
}

/* ---------- VIEW ALL ---------- */
void viewAll()
{
    printf("\nID           Name              Vehicle             Hrs     Cost         Date           Time\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < rcount; i++) {
        printf("%-10d |%-18s |%-17s |%-7d ₹%-9.2f |%-15s |%-15s|\n",
            rentArr[i].rid, rentArr[i].cname,
            vname(rentArr[i].vtype),
            rentArr[i].hrs, rentArr[i].cost,
            rentArr[i].date, rentArr[i].time);
    }
}

/* ---------- SEARCH ---------- */
void searchRec()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for(int i = 0; i < rcount; i++) {
        if(rentArr[i].rid == id) {
            printf("Found: %s ₹%.2f\n",
                rentArr[i].cname,
                rentArr[i].cost);
            return;
        }
    }
    printf("Not Found!\n");
}

/* ---------- DELETE ---------- */
void deleteRec()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for(int i = 0; i < rcount; i++) {
        if(rentArr[i].rid == id) {
            for(int j = i; j < rcount-1; j++)
                rentArr[j] = rentArr[j+1];
            rcount--;
            printf("Deleted!\n");
            return;
        }
    }
}

/* ---------- UPDATE ---------- */
void updateRec()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for(int i = 0; i < rcount; i++) {
        if(rentArr[i].rid == id) {
            printf("New Name: ");
            scanf(" %59[^\n]", rentArr[i].cname);
            printf("New Hours: ");
            scanf("%d", &rentArr[i].hrs);
            rentArr[i].cost = rentArr[i].hrs * vrates[rentArr[i].vtype];
            printf("Updated!\n");
            return;
        }
    }
}

/* ---------- BILL ---------- */
void printBill()
{
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for(int i = 0; i < rcount; i++) {
        if(rentArr[i].rid == id) {
            printf("Name: %s Cost: ₹%.2f\n",
                rentArr[i].cname,
                rentArr[i].cost);
            return;
        }
    }
}

/* ---------- REPORT ---------- */
void dailyReport()
{
    float total = 0;
    for(int i = 0; i < rcount; i++)
        total += rentArr[i].cost;

    printf("Total Income: ₹%.2f\n", total);
}

/* ---------- FILE ---------- */
void saveFile()
{
    FILE *fp = fopen("vehRent.dat", "wb");
    fwrite(rentArr, sizeof(struct rentalRec), rcount, fp);
    fclose(fp);
}

void loadFile()
{
    FILE *fp = fopen("vehRent.dat", "rb");
    if(fp) {
        rcount = fread(rentArr, sizeof(struct rentalRec), RENT_REC, fp);
        fclose(fp);
    }
}
