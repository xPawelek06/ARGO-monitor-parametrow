#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int wybor;
    char znak;
    char numer_nazwa[3][20] = {"Plasma", "Cryo Shield", "EMP"};

    printf("Witaj na pokladzie statku badawczego ARGO!\n");
    printf("1. %s\n", numer_nazwa[0]);
    printf("2. %s\n", numer_nazwa[1]);
    printf("3. %s\n", numer_nazwa[2]);
    printf("Wybierz jeden z trzech trybow: ");
    if (scanf("%d%c", &wybor, &znak) == 2 && znak == '\n') {
        if (wybor < 1 || wybor > 3) {
            printf("Musisz podac liczbe calkowita 1, 2 lub 3!\n");
            return 1;
        }

        int wybor_systemu = (rand() % 3) + 1;


        if ((wybor == 1 && wybor_systemu == 2) || (wybor == 2 && wybor_systemu == 3) || (wybor == 3 && wybor_systemu == 1)) {
            printf("Twoj wybor to %s, a wybor systemu to %s. Wybrany tryb okazal sie lepszy! Wygrales\n", numer_nazwa[wybor-1], numer_nazwa[wybor_systemu-1]);
        }
        else if (wybor == wybor_systemu) {
            printf("Twoj wybor to %s, a wybor systemu to %s. Wybraliscie tak samo! Remis\n", numer_nazwa[wybor-1], numer_nazwa[wybor_systemu-1]);
        } 
        else {
            printf("Twoj wybor to %s, a wybor systemu to %s. Niestety system dokonal lepszego wyboru. Przegrywasz!\n", numer_nazwa[wybor-1], numer_nazwa[wybor_systemu-1]);
        }
    } else {
        printf("Podales niepoprawne dane! Wybierz 1, 2 lub 3.\n");
        return 1;
    }

    return 0;
}