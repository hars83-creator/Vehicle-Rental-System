#ifndef VEHICLERENTAL_H
#define VEHICLERENTAL_H

#define RENT_REC 100

// enum for declaring veehicle a number that is  starting from 1 for easily calling ..
enum vehicleType {
    V_BIKE=1, V_SCOOTY, V_CYCLE, V_EBIKE, V_MBIKE,
    V_MSZK, V_THAR, V_SCORP, V_BULLET
};

struct rentalRec {
    int rid;
    char cname[60];
    int vtype;
    int hrs;
    float cost;
};

extern struct rentalRec rentArr[RENT_REC];
extern int rcount;
extern float vrates[];

void showVehicles();
const char* vname(int t);
void addRent();
void viewAll();
void saveFile();
void loadFile();

#endif