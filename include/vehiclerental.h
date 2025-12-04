#ifndef RENTAL_H
#define RENTAL_H

#include <time.h>

#define RENT_REC 1000
#define ADMIN_PASS "1234"

/* ---------- VEHICLE ENUM ---------- */
enum vehicleType {
    V_BIKE = 1, V_SCOOTY, V_CYCLE, V_EBIKE, V_MBIKE,
    V_MSZK, V_THAR, V_SCORP, V_BULLET
};

/* ---------- RENTAL STRUCT ---------- */
struct rentalRec {
    int rid;
    char cname[60];
    int vtype;
    int hrs;
    float cost;
    char date[20];
    char time[20];
};

/* ---------- GLOBAL DATA ---------- */
extern struct rentalRec rentArr[RENT_REC];
extern int rcount;
extern float vrates[10];

/* ---------- FUNCTION PROTOTYPES ---------- */
void showVehicles();
const char* vname(int);
int login();
void addRent();
void viewAll();
void searchRec();
void deleteRec();
void updateRec();
void printBill();
void dailyReport();
void saveFile();
void loadFile();

#endif
