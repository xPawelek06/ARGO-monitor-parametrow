#include <stdio.h>

int main(void) {
    float waga;
    char znak;

    printf("Podaj wage walizki: ");
    if (scanf("%f%c", &waga, &znak) == 2 && znak == '\n') {
        printf("Waga bagazu: %.2fkg\n", waga);
        if (waga < 0 || waga > 200) {
            printf("Niepoprawne dane\n");
        } else if (waga <= 23) {
            printf("Bagaz zaakceptowany bez oplat\n");
        } else if (waga <= 32) {
            printf("Wymagany jest dodatkowy koszt za nadbagaz\n");
        } else {
            printf("Bagaz nie moze byc przyjety\n");
        }
    } else {
        printf("Podaj liczbe bez znakow!\n");
        while(getchar() != '\n');
    }

    return 0;
}