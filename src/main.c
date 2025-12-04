#include <stdio.h>
#include "rental.h"

int main()
{
    int ch;
    loadFile();

    if(!login()) return 0;

    do {
          printf("\n1.Add \t\t        2.View\n3.Search\t\t 4.Delete \n5.Update\t\t6.Bill \n7.Report \t\t8.Save \n0.Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: addRent(); break;
            case 2: viewAll(); break;
            case 3: searchRec(); break;
            case 4: deleteRec(); break;
            case 5: updateRec(); break;
            case 6: printBill(); break;
            case 7: dailyReport(); break;
            case 8: saveFile(); break;
        }
    } while(ch != 0);

    saveFile();
    return 0;
}
