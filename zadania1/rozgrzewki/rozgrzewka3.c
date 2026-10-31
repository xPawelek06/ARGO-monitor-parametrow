#include <stdio.h>

int main(void) {
    int rok;
    char znak;

    printf("Podaj rok: ");
    if (scanf("%d%c", &rok, &znak) == 2) {
        if(rok < 0) {
            printf("Rok nie moze byc ujemny.\n");
            return 1;
        }
        else if(znak != '\n') {
            printf("Podaj liczbe calkowita bez ulamkow lub innych znakow.\n");
            return 1;
        } else {
            if (rok % 400 == 0 || (rok % 4 == 0 && rok % 100 != 0)) {
                printf("Rok %d jest przestepny.\n", rok);
            }
            else {
                printf("Rok %d nie jest przestepny.\n", rok);
            }
        }
    } else {
        printf("Niepoprawne dane wejsciowe. Podaj liczbe calkowita!\n");
        return 1;
    }

    return 0;
}