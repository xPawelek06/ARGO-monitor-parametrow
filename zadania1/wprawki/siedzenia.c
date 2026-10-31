#include <stdio.h>

#define WARIANT_A 3 //rzedy po 3 miejsca
#define WARIANT_B 5 //rzedy po 5 miejsc

int main(void) {
    int liczba_pasazerow;
    char znak;
    int dziala = 1;


    printf("Witaj w programie wspomagajacym dobranie siedzien pod pasazerow!\n");
    printf("Do dyspozycji sa dwa warianty:\n");
    printf("Wariant A: po 3 miejsca w rzedzie\n");
    printf("Wariant B: po 5 miejsc w rzedzie\n");

    while (dziala) {
        printf("Podaj liczbe pasazerow: ");
        if (scanf("%d%c", &liczba_pasazerow, &znak) == 2 && znak == '\n') {
            if (liczba_pasazerow <= 0) {
                printf("Liczba pasazerow musi byc wieksza od 0\n");
                continue;
            }

            int puste_miejsca_A;
            int puste_miejsca_B;
            int potrzebne_rzedy_A;
            int potrzebne_rzedy_B;

            potrzebne_rzedy_A = liczba_pasazerow / WARIANT_A;
            if (liczba_pasazerow % WARIANT_A != 0) {potrzebne_rzedy_A++;}

            potrzebne_rzedy_B = liczba_pasazerow / WARIANT_B;
            if (liczba_pasazerow % WARIANT_B != 0) {potrzebne_rzedy_B++;}

            if (liczba_pasazerow % WARIANT_A == 0) {
                puste_miejsca_A = 0;
            } else {
                puste_miejsca_A = WARIANT_A - (liczba_pasazerow % WARIANT_A);
            }

            if (liczba_pasazerow % WARIANT_B == 0) {
                puste_miejsca_B = 0;
            } else {
                puste_miejsca_B = WARIANT_B - (liczba_pasazerow % WARIANT_B);
            }

            if (puste_miejsca_A == puste_miejsca_B) {
                printf("Przy %d pasazerach wariant A jak i wariant B sa dobrymi wyborami\n", liczba_pasazerow);
            } else if (puste_miejsca_A < puste_miejsca_B) {
                printf("Przy %d pasazerach lepiej wybrac wariant A\n", liczba_pasazerow);
            } else {
                printf("Przy %d pasazerach lepiej wybrac wariant B\n", liczba_pasazerow);
            }

            if (puste_miejsca_A == 0 && puste_miejsca_B == 0) {
                printf("Oba warianty przy %d pasazerach nie beda mialy wolnych miejsc\n", liczba_pasazerow);
            } else if (puste_miejsca_A == 0) {
                printf("W wariancie A przy %d pasazerach nie bedzie wolnych miejsc\n", liczba_pasazerow);
            } else if (puste_miejsca_B == 0) {
                printf("W wariancie B przy %d pasazerach nie bedzie wolnych miejsc\n", liczba_pasazerow);
            }

            printf("--- STATYSTYKI ---\n");
            printf("WARIANT A:\n");
            printf("Liczba potrzebnych rzedow: %d\n", potrzebne_rzedy_A);
            printf("Wolne miejsca: %d\n", puste_miejsca_A);
            printf("WARIANT B:\n");
            printf("Liczba potrzebnych rzedow: %d\n", potrzebne_rzedy_B);
            printf("Wolne miejsca: %d\n", puste_miejsca_B);

            dziala = 0;

        } else {
            printf("Musisz podac liczbe calkowita!\n");
            while(getchar() != '\n');
        }
    }   

    return 0;
}