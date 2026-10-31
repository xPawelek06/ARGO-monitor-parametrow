#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int liczba_scian;
    char znak;

    printf("Podaj liczbe scian kostki wieksza od 4: ");
    if ((scanf("%d%c", &liczba_scian, &znak) == 2 && znak == '\n')) {
        if (liczba_scian <=4) {
            printf("Liczba scian musi byc wieksza od 4.\n");
            return 1;
        } else {
            int wynik = (rand() % liczba_scian) + 1;
            printf("Wynik rzutu kostka o %d scianach: %d.\n", liczba_scian, wynik);
        }
    } else {
        printf("Podaj liczbe calkowita!\n");
        return 1;
    }

    return 0;
}