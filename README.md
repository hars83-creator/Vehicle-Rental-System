# Vehicle-Rental-System
🚗 🚗 🚗 🚗 🚗 🚗 C Major Project – Vehicle Rental System 🚗 🚗 🚗 🚗 🚗  

Rental Roadies is a mini-project built in C that helps manage a vehicle rental service.  
This system allows rental entry, cost calculation, data storing ....

name of this project 
**********************************************************
*        ⭐⭐⭐⭐    RENTAL ROADIES     ⭐⭐⭐⭐            *
**********************************************************


**********************************************************
*             ⭐ Project Summary ⭐                       *
**********************************************************
Add a customer’s rental information  
- Select a vehicle from a list of 9 types  
- Enter rental hours and add total charges
- View all previous rentals  
- Save or load data using a binary file (`vehRent.dat`)  
- Everything run from a simple menu on the terminal  

**********************************************************
*             ⭐     FEATURES    ⭐                       *
**********************************************************
✨ Featur of this program is follows:
___________
ADD RENTAL
-----------
🌟 input customer name 
🌟 verify license id (5 digit)
🌟 select vehicle from the list 
🌟 Enter hours 
🌟 auto calculation of charges .
______________________
all previous record 
----------------------
🌟 customer name , vehicle type , time for rent , cost .
______________
saving file 
--------------
🌟 all record save in file "vehRent.dat" ..
________________
clear interface 
----------------
🌟 use clear function for clering screen for clean interface .
________________
modular layout
----------------
🌟 separte .c & .h files

**********************************************************
*     ⭐  Compilation and execution instructions ⭐       *
**********************************************************

each file has its own purpose and together they form the full program.
____________________________________
How to Compile & Run It
____________________________________
In  GCC, the program can be compiled with a single command:

gcc -I include src/main.c src/utils.c src/vehiclerental.c -o main      

Once it compiles , you can run it like (   ./main  ).

**********************************************************
*     ⭐   Directory structure     ⭐                     *
**********************************************************
ProjectFolder
⚡️├── main.c             -> main source file 
⚡️├── data/             ->  folder for storing all generated files
⚡️│     ├── accounts.dat
⚡️│     └── transactions.dat
│
⚡️└── README.md            -> about project and how to use it


**********************************************************
*     ⭐ Concepts demonstrated   ⭐
**********************************************************

* Structures
-    Used to store each rental’s details in a clean, organized way.

* Enums
-   Helps to map vehicle types to meaningful names.

* File Handling (Binary I/O)
- Data is saved using fwrite() and loaded using fread().

* Modular Programming
- The program demonstrates how to break logic across different files instead of writing everything in one long file.

* Arrays
- Stores all rental entries (up to 100).

* Condition checks & loops
- For validating inputs and navigating through the menu.

**********************************************************
*     ⭐ future implementation  ⭐
**********************************************************

 This project is made for only learning and in future adding of many features like 

 ⚡️vehicle penalty charge after late 
 ⚡️driving license check with Eparivahan portal.
 ⚡️customer book through app 
 ⚡️record of vehicle paper for police checking 
 
