#include <stdlib.h>

void clerscrn()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
