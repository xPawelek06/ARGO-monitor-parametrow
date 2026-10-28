#include "logowanie.h"
#include "menu.h"
#include "odczyty.h"

int main(void) {
    int liczba_odczytow = 0;
    int odczyty[MAX_ODCZYTOW];

    while(logowanie() == 1) {
        menu(odczyty, &liczba_odczytow);
    }
    return 0;
}