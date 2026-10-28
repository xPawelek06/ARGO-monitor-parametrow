#include <stdio.h>
#include <string.h>
#include "logowanie.h"

#define LOGIN "abc@argo.com"
#define HASLO "abc_argo"

int logowanie(void) {
    char login[20];
    char haslo[20];
    int proby_logowania = 1;

    printf("Witaj na pokladzie statku badawczego ARGO!\n");
    printf("Zanim zaczniesz, musisz sie zalogowac\n");
    printf("Twoj login: %s\n", LOGIN);
    printf("Twoje haslo: %s\n", HASLO);

    for(; proby_logowania <= 3; proby_logowania++) {
        printf("Podaj login: ");
        if (scanf("%19s", login) != 1 || strcmp(login,  LOGIN) != 0) {
            printf("Niepoprawny login, masz jeszcze %d prob\n", (3-proby_logowania));
            while(getchar() != '\n');
            continue;
        }

        printf("Podaj haslo: ");
        if (scanf("%19s", haslo) == 1 && strcmp(haslo,  HASLO) == 0) {
            printf("Udalo ci sie zalogowac!\n");
            return 1;
        } else {
            printf("Niepoprawne haslo, masz jeszcze %d prob\n", (3-proby_logowania));
            while(getchar() != '\n');
        }
    }

    printf("Zbyt wiele prob logowania\n");
    return 0;
}