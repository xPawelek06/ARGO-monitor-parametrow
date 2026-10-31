#include <stdio.h>
#include "menu.h"
#include "odczyty.h"

int pobierz_liczbe(void) {
    int liczba;
    char znak;
    while(1) {
        if(scanf("%d%c", &liczba, &znak) == 2 && znak == '\n') {
            return liczba;
        } else {
            printf("Musisz podac liczbe! ");
            while( getchar() != '\n');
        }
    }
}

void menu(int odczyty[], int *liczba_odczytow) {
    int zalogowany = 1;
    int wybor;

    while(zalogowany) {
        printf("--- MENU ---\n");
        printf("1. Dodaj nowy odczyt\n");
        printf("2. Zmien wybrany odczyt\n");
        printf("3. Wyswietl zapisane odczyty\n");
        printf("4. Wyswietl podstawowe statystyki\n");
        printf("5. Wyswietl odczyty przekraczajace ustalony poziom alarmowy\n");
        printf("6. Wyczysc zapisane dane\n");
        printf("7. Wylogowanie\n");

        printf("Wybierz opcje: ");
        wybor = pobierz_liczbe();

        switch (wybor)
        {
        case 1: {
            dodaj_odczyt(odczyty, liczba_odczytow);
            break;
        }

        case 2: {
            zmien_wybrany_odczyt(odczyty, *liczba_odczytow);
            break;
        }

        case 3: {
            wyswietl_zapisane_odczyty(odczyty, *liczba_odczytow);
            break;
        }

        case 4: {
            wyswietl_statystyki(odczyty, *liczba_odczytow);
            break;
        }

        case 5: {
            wyswietl_odczyty_ponad_poziom_alarmowy(odczyty, *liczba_odczytow);
            break;
        }

        case 6: {
            wyczysc_zapisane_dane(liczba_odczytow);
            break;
        }

        case 7: {
            printf("Wylogowano\n");
            zalogowany = 0;
            break;
        }
        
        default:
        printf("Musisz podac liczbe calkowita z przedzialu 1-7!\n");
            break;
        }
    }
}