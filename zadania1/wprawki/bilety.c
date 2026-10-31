#include <stdio.h>

#define BILET_NORMALNY 4
#define BILET_ULGOWY 2

int pobierz_wybor(void) {
    int wybor;
    char znak;
    while (1) {
        if (scanf("%d%c", &wybor, &znak) == 2 && znak == '\n') {
        return wybor;
        } else {
            printf("Niepoprawny wybor. Musisz podac liczbe calkowita: ");
            while(getchar() != '\n');
            continue;
        }
    }
}

int main(void) {
    int rodzaj_biletu;
    int czy_dziala = 1;
    
    while(czy_dziala) {
        printf("---- AUTOMAT BILETOW ----\n");
        printf("1. Bilet normalny: 4zl\n");
        printf("2. Bilet ulgowy: 2zl\n");
        printf("3. Anuluj kupno\n");
        printf("Ktory bilet chcesz kupic? ");
        rodzaj_biletu = pobierz_wybor();

        if (rodzaj_biletu == 3) {
            czy_dziala = 0;
            break;
        } else if (rodzaj_biletu != 1 && rodzaj_biletu != 2) {
            printf("Musisz podac liczbe calkowita 1, 2 lub 3!\n");
            continue;
        }

        int ilosc_biletow;
        float kwota_klienta;

        printf("Ile biletow chcesz kupic? ");
        ilosc_biletow = pobierz_wybor();
        if (ilosc_biletow <= 0) {
            printf("Ilosc biletow musi byc dodatnia!\n");
            continue;
        }
        char znak;
        int koniec = 1;
        do {
            printf("Podaj swoja kwote: ");
            if (scanf("%f%c", &kwota_klienta, &znak) == 2 && znak == '\n') {
                koniec = 0;
            } else {
                printf("Musisz podac liczbe!\n");
                while (getchar() != '\n');
            }
        } while (koniec);

        int suma;
        if (rodzaj_biletu == 1) {
            suma = ilosc_biletow * BILET_NORMALNY;
        }
        if (rodzaj_biletu == 2) {
            suma = ilosc_biletow * BILET_ULGOWY;
        }

        printf("Dajesz: %.2fzl\n", kwota_klienta);
        printf("Do zaplaty: %dzl\n", suma);

        float reszta = kwota_klienta - (float)suma;

        if (rodzaj_biletu == 1 && reszta >= 0) {
            if (((ilosc_biletow % 10 == 2 && ilosc_biletow % 100 != 12) || (ilosc_biletow % 10 == 3 && ilosc_biletow % 100 != 13) || (ilosc_biletow % 10 == 4 && ilosc_biletow % 100 != 14))) {
                printf("Drukuje %d bilety normalne\n", ilosc_biletow);
            } else if (ilosc_biletow == 1) {
                printf("Drukuje %d bilet normalny\n", ilosc_biletow);
            } else {
                printf("Drukuje %d biletow normalnych\n", ilosc_biletow);
            }
        }

        if (rodzaj_biletu == 2 && reszta >= 0) {
            if (((ilosc_biletow % 10 == 2 && ilosc_biletow % 100 != 12) || (ilosc_biletow % 10 == 3 && ilosc_biletow % 100 != 13) || (ilosc_biletow % 10 == 4 && ilosc_biletow % 100 != 14))) {
                printf("Drukuje %d bilety ulgowe\n", ilosc_biletow);
            } else if (ilosc_biletow == 1) {
                printf("Drukuje %d bilet ulgowy\n", ilosc_biletow);
            } else {
                printf("Drukuje %d biletow ulgowych\n", ilosc_biletow);
            }
        }

        if (reszta == 0) {
            printf("Reszta: %.0fzl\n", reszta);
        } else if (reszta > 0) {
            printf ("Reszta: %.2fzl\n", reszta);
        } else {
            printf ("Niewystarczajaca kwota, brakuje: %.2fzl\n", -reszta);
            continue;
        }
        czy_dziala = 0;
    }

    return 0;
}