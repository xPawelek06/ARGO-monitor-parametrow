#ifndef ODCZYTY_H
#define ODCZYTY_H

void dodaj_odczyt(int odczyty[], int *liczba_odczytow);
void zmien_wybrany_odczyt(int odczyty[], int liczba_odczytow);
void wyswietl_zapisane_odczyty(int odczyty[], int liczba_odczytow);
void wyswietl_statystyki(int odczyty[], int liczba_odczytow);
void wyswietl_odczyty_ponad_poziom_alarmowy(int odczyty[], int liczba_odczytow);
void wyczysc_zapisane_dane(int *liczba_odczytow);

#define MAX_ODCZYTOW 8
#define MIN_ODCZYT -50
#define MAX_ODCZYT 50
#define PROG_ALARMOWY_MIN -40
#define PROG_ALARMOWY_MAX 40

#endif