#ifndef VEHICLERENTAL_H
#define VEHICLERENTAL_H

// Maximum number of rental records that can be stored in memory
#define RENT_REC 5000    // limit can be increased later if required

// Enum for vehicle type selection in menu
// Starting from 1 makes menu handling easier
enum vehicleType
{
    V_BIKE = 1,
    V_SCOOTY,
    V_CYCLE,
    V_EBIKE,
    V_MBIKE,
    V_MSZK,
    V_THAR,
    V_SCORP,
    V_BULLET
};

// Structure to store a single rental record
struct rentalRec
{
    int rid;             // license ID of customer
    char cname[60];      // customer name
    int vtype;           // selected vehicle type
    int hrs;             // number of hours rented
    float cost;          // total rental cost
};

// Global variables used in multiple files
extern struct rentalRec rentArr[RENT_REC];   // array to store all rental records
extern int rcount;                           // total number of records stored
extern float vrates[];                      // hourly rates of vehicles

// Function declarations
void showVehicles();        // displays vehicle list
const char* vname(int t);  // returns vehicle name based on type
void addRent();            // adds a new rental record
void viewAll();            // displays all records
void saveFile();           // saves records to file
void loadFile();           // loads records from file

#endif
