#include <stdio.h>

int pobierz_wymiar(int ktory) {
    int liczba;
    char znak;

    while(1) {
        printf("Podaj %d wymiar: ", ktory);

        if(scanf("%d%c", &liczba, &znak) == 2 && znak == '\n') {
            if (liczba <= 0) {
                printf("Musisz podac liczbe dodatnia\n");
                continue;
            }

            return liczba;

        } else {
            printf("Musisz podac liczbe calkowita!\n");
            while (getchar() != '\n');
        }
    }
}

void czy_kat_prosty(int przyprostokatna1, int przyprostokatna2, int przeciwprostokatna) {
    if (przyprostokatna1*przyprostokatna1 + przyprostokatna2*przyprostokatna2 == przeciwprostokatna*przeciwprostokatna) {
        printf("Elementy ustawione sa pod katem prostym\n");
    } else {
        printf("Elementy nie sa ustawione pod katem prostym\n");
    }
}

int main(void) {
    int a;
    int b;
    int c;

    printf("--- MONTAZ KONSTRUKCJI ---\n");
    printf("Sprawdzmy, czy dwa elementy stoja pod katem prostym\n");

    a = pobierz_wymiar(1);
    b = pobierz_wymiar(2);
    c = pobierz_wymiar(3);

    if (a > c && a > b) {
        czy_kat_prosty(b,c,a);
    } else if (b > a && b > c) {
        czy_kat_prosty(a,c,b);
    } else if (c > a && c > b) {
        czy_kat_prosty(a,b,c);
    } else {
        printf("Elementy nie sa ustawione pod katem prostym\n");
    }
    
    return 0;
}