#include <stdio.h>

int main(void) {
    int a, b;
    printf("Podaj dwie liczby calkowite: ");

    if (scanf("%d %d", &a, &b) == 2) {
        int suma = a + b;
        float srednia = suma / 2.0;

        printf("Suma: %d\n", suma);
        printf("Srednia: %.1f\n", srednia);
    }
    else {
        printf("Niepoprawne dane wejsciowe.\n");
        return 1;
    }

    return 0;
}
