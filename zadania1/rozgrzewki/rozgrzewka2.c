#include <stdio.h>

int main(void) {
    int a, b;
    printf("Podaj dwie liczby calkowite: ");
    if (scanf("%d %d", &a, &b) == 2) {
        if (a % 2 == 0 && b % 2 == 0) {
            printf("Obie liczby sa parzyste.\n");
        }
        else if (a % 2 != 0 && b % 2 != 0) {
            printf("Obie liczby sa nieparzyste.\n");
        }
        else {
            printf("Jedna liczba jest parzysta, a druga nieparzysta.\n");
        }
    }
    else {
        printf("Niepoprawne dane wejsciowe. Podaj liczby calkowite!\n");
        return 1;
    }
    return 0;
}