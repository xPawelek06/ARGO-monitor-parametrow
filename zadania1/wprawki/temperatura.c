#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int temp = (rand() % 46 - 10);

    printf("Temperature: %d\n", temp);
    if (temp < 1) {
        printf("Frost. Wear warm clothes\n");
    } else if (temp <= 25) {
        printf("Weather conditions are comfortable\n");
    } else {
        printf("High temperature. Avoid overheating\n");
    }

    return 0;
}