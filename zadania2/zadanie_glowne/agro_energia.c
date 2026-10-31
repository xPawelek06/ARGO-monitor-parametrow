#include <stdio.h>

#define SYSTEM_NAWIGACYJNY 50
#define MODUL_BADAWCZY 70

int pobierz_liczbe(void) {
    int liczba;
    char znak;
    while (1)
    {
        if (scanf("%d%c", &liczba, &znak) == 2 && znak == '\n') {
            return liczba;
        } else {
            printf("To nie jest liczba. Sprobuj jeszcze raz: ");
            while(getchar() != '\n');
        }
    }
}

int main (void) {
    int poziom_energii = 20;
    int kod_dostepu = 20060731;
    int podany_kod_dostepu;
    int wybor = 1;

    printf("Witaj w systemie zarzadzania energia!\n");
    printf("Zanim cokolwiek bedziesz mogl zrobic, musisz sie zalogowac.\n");
    printf("Twoj kod dostepu: %d\n", kod_dostepu);
    
    while(1) {
        int proby_logowania = 1;

        for (;proby_logowania <= 3; proby_logowania++) {
            printf("Wpisz swoj kod dostepu: ");
            podany_kod_dostepu = pobierz_liczbe();
            
            if (podany_kod_dostepu == kod_dostepu) {
                printf("Udalo ci sie zalogowac! Witaj na pokladzie.\n");
                break;
            } else {
                printf("Niepoprawny kod dostepu, sprobuj ponownie...\n");
            }
        }
        if (proby_logowania >= 4) {
            printf("Zbyt wiele nieudanych prob logowania.");
            return 1;
        }

        do {
            printf("----------- MENU -----------\n");
            printf("1. Charge the energy core\n");
            printf("2. Power the navigation system\n");
            printf("3. Power the research module\n");
            printf("4. Check energy level\n");
            printf("5. Run reactor diagnostics\n");
            printf("0. Log out\n");
            printf("Wybierz opcje z menu: ");

            wybor = pobierz_liczbe();

            switch (wybor) {
            case 1: {
                int doladowanie;
                int petla_doladowania = 1;
                printf("Aktualny poziom energii to: %d.\n", poziom_energii);

                while (petla_doladowania) {
                    printf("Ile energii chcesz doladowac? ");
                    doladowanie = pobierz_liczbe();

                    if (doladowanie > 0 && doladowanie <= 100) {
                        if (doladowanie + poziom_energii <= 100) {
                            poziom_energii += doladowanie;
                            printf("Udalo sie doladowac energie!\n");
                        } else if (poziom_energii == 100) {
                            printf("Nie mozesz doladowac energii. Energia ma maksymalny poziom\n");
                        } else {
                            poziom_energii = 100;
                            printf("Doladowano energie do: %d. Nie da sie wiecej!\n", poziom_energii);
                        }
                        
                        petla_doladowania = 0;
                    } else {
                        printf("Aby doladowac energie, musisz podac liczbe calkowita z przedzialu 1-100\n");
                    }
                }
                break;
            }
            
            case 2: {
                if (poziom_energii >= SYSTEM_NAWIGACYJNY) {
                    poziom_energii -= SYSTEM_NAWIGACYJNY;
                    printf("Zasilono system nawigacyjny!\n");
                } else {
                    printf("Masz za malo energii, aby doladowac system nawigacyjny\n");
                }
                break;
            }
            
            case 3: {
                if (poziom_energii >= MODUL_BADAWCZY) {
                    poziom_energii -= MODUL_BADAWCZY;
                    printf("Zasilono modul badawczy!\n");
                } else {
                    printf("Masz za malo energii, aby zasilic modul badawczy\n");
                }
                break;
            }

            case 4: {
                if (poziom_energii < 25) {
                    printf("Aktualny poziom energii - CRITICAL: %d\n", poziom_energii);
                } else if (poziom_energii < 50) {
                    printf("Aktualny poziom energii - LOW: %d\n", poziom_energii);
                } else if (poziom_energii < 75) {
                    printf("Aktualny poziom energii - NORMAL: %d\n", poziom_energii);
                } else {
                    printf("Aktualny poziom energii - HIGH: %d\n", poziom_energii);
                }
                break;
            }

            case 5: {
            int liczba_pomiarow;
            int suma = 0;
            int max;
            int min;
            int prog_alarmowy = 500;
            int ilosc_alarmow = 0;
            int temp;

                printf("Ile pomiarow temperatury reaktora podasz? ");
                liczba_pomiarow = pobierz_liczbe();

                if (liczba_pomiarow <= 0) {
                    printf("Liczba pomiarow musi byc calkowita i wieksza od 0!\n");
                    continue;
                }
                for (int i = 1; i <= liczba_pomiarow; i++) {
                    printf("Pomiar %d: ", i);
                    temp = pobierz_liczbe();

                    if (i == 1) {
                        max = temp;
                        min = temp;
                    }
                    suma += temp;
                    if (temp >= prog_alarmowy) {
                        ilosc_alarmow++;
                        printf("Temperatura %d C przekracza prog alarmowy!\n", temp);
                    }
                    if (temp > max) {
                        max = temp;
                    } 
                    if (temp < min) {
                        min = temp;
                    }
                }
                
                float srednia = suma / (float)liczba_pomiarow;

                printf("------ WYNIKI DIAGNOSTYKI ------\n");
                printf("Minimalna wartosc: %d\n", min);
                printf("Maksymalna wartosc: %d\n", max);
                printf("Suma: %d\n", suma);
                printf("Srednia pomiarow: %.1f\n", srednia);
                printf("Ilosc wystepionych alarmow: %d\n", ilosc_alarmow);
                break;
            }

            case 0: {
                printf("Wylogowano\n");
                break;
            }

            default: 
                printf("Musisz podac liczbe calkowita w przedziale 0-5!\n");
                continue;
            }
        } while (wybor);
    }
    return 0;
}