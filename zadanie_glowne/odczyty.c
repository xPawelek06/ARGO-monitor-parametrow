#include <stdio.h>
#include "odczyty.h"
#include "menu.h"

void dodaj_odczyt(int odczyty[], int *liczba_odczytow) {
    int poprawne = 1;
    int wartosc;

    while(poprawne) {
        printf("Podaj wartosc odczytu: ");
        wartosc = pobierz_liczbe();

        if (wartosc < MIN_ODCZYT || wartosc > MAX_ODCZYT) {
                printf("Odczyt musi miescic sie w przedziale: [%d;%d]\n", MIN_ODCZYT, MAX_ODCZYT);
                continue;
            }

        if (*liczba_odczytow == MAX_ODCZYTOW) {
            for (int i = 0; i <= MAX_ODCZYTOW-2; i++) {
                odczyty[i] = odczyty[i+1];
            }
            odczyty[MAX_ODCZYTOW-1] = wartosc;
            poprawne = 0;
        } else {
            printf("Nowy odczyt: %d\n", wartosc);
            odczyty[*liczba_odczytow] = wartosc;
            (*liczba_odczytow)++;
            poprawne = 0;
        }
    }
}

void zmien_wybrany_odczyt(int odczyty[], int liczba_odczytow) {
    int nr_odczytu;
    int nowa_wartosc;

    if (liczba_odczytow == 0) {
        printf("Brak zapisanych odczytow\n");
    } else {
        while(1) {
            printf("0. Anuluj\n");
            for (int i = 1; i <= liczba_odczytow; i++) {
            printf("%d. %d\n", i, odczyty[i-1]);
            }

            printf("Ktory odczyt chcesz zmienic: ");
            nr_odczytu = pobierz_liczbe();

            if (nr_odczytu == 0) break;
            if (nr_odczytu < 1 || nr_odczytu > liczba_odczytow) {
                printf("Musisz podac liczbe z przedzialu liczby odczytow!\n");
                continue;
            }

            printf("Podaj nowa wartosc odczytu: ");
            nowa_wartosc = pobierz_liczbe();
            if (nowa_wartosc < MIN_ODCZYT || nowa_wartosc > MAX_ODCZYT) {
                printf("Odczyt musi miescic sie w przedziale: [%d;%d]\n", MIN_ODCZYT, MAX_ODCZYT);
                continue;
            } else if (nowa_wartosc == odczyty[nr_odczytu-1]) {
                printf("Nie mozesz zmienic wartosci na ta sama\n");
                continue;
            } else {
                printf("Pomyslnie zastapiono odczyt nowa wartocia\n");
                odczyty[nr_odczytu-1] = nowa_wartosc;
                break;
            }
        }
    }
}

void wyswietl_zapisane_odczyty(int odczyty[], int liczba_odczytow) {
    if (liczba_odczytow == 0) {
        printf("Brak zapisanych odczytow\n");
    } else {
        for (int i = 1; i <= liczba_odczytow; i++) {
            printf("%d. %d\n", i, odczyty[i-1]);
        }
    }
}

void wyswietl_statystyki(int odczyty[], int liczba_odczytow) {
    int suma = 0;
    int max_wzrost;
    int max_spadek;
    float srednia;
    int roznica;

    if (liczba_odczytow == 0) {
        printf("Brak zapisanych odczytow\n");
        printf("Dodaj je, aby wyswietlic statystyki\n");
    } else if (liczba_odczytow == 1) {
        printf("Potrzebujesz co najmniej dwoch odczytow, aby wyswietlic statystyki\n");
    } else {
        for (int i = 1; i <= liczba_odczytow; i++) {
            suma += odczyty[i-1];

            if (i < liczba_odczytow) {
                roznica = odczyty[i] - odczyty[i-1];
                if (i == 1) {
                    max_wzrost = roznica;
                    max_spadek = roznica;
                }
                if (max_spadek > roznica) {
                    max_spadek = roznica;
                }
                if (max_wzrost < roznica) {
                    max_wzrost = roznica;
                }
            }

        }
        srednia = suma / (float)liczba_odczytow;
        int liczba_odczytow_ponad_srednia = 0;

        for (int i = 1; i <= liczba_odczytow; i++) {
            if ((float)odczyty[i-1] > srednia) {
                liczba_odczytow_ponad_srednia++;
            }
        }

        printf("Ilosc odczytow ponad srednia: %d\n", liczba_odczytow_ponad_srednia);
        if (max_wzrost <= 0 && max_spadek >= 0) {
            printf("Srednia wartosc odczytow: %.2f\n", srednia);
        } else if (max_wzrost > 0 && max_spadek >= 0) {
            printf("Srednia wartosc odczytow: %.2f\n", srednia);
            printf("Maksymalny wzrost: %d\n", max_wzrost);
        } else if (max_wzrost <= 0 && max_spadek < 0) {
            printf("Srednia wartosc odczytow: %.2f\n", srednia);
            printf("Maksymalny spadek: %d\n", max_spadek);
        } else {
            printf("Srednia wartosc odczytow: %.2f\n", srednia);
            printf("Maksymalny wzrost: %d\n", max_wzrost);
            printf("Maksymalny spadek: %d\n", max_spadek);
        }
    }
}

void wyswietl_odczyty_ponad_poziom_alarmowy(int odczyty[], int liczba_odczytow) {
    int ilosc_odczytow_przekraczajacych = 0;
    int odczyty_przekraczajace[MAX_ODCZYTOW];

    for (int i = 1; i <= liczba_odczytow; i++) {
        if (odczyty[i-1] < PROG_ALARMOWY_MIN || odczyty[i-1] > PROG_ALARMOWY_MAX) {
            odczyty_przekraczajace[ilosc_odczytow_przekraczajacych] = odczyty[i-1];
            ilosc_odczytow_przekraczajacych++;
        }
    }
    if (ilosc_odczytow_przekraczajacych == 0) {
            printf("Brak odczytow przekraczajacych poziom alarmowy\n");
        } else {
            printf("Odczyty przekraczajace poziom alarmowy:\n");   
            
            for (int i = 1; i <= ilosc_odczytow_przekraczajacych; i++) {
                printf("%d. %d\n", i, odczyty_przekraczajace[i-1]);
            }
  
        }
}

void wyczysc_zapisane_dane(int *liczba_odczytow) {
    printf("Pomyslnie wyczyszczono wszystkie odczyty\n");
    (*liczba_odczytow) = 0;
}