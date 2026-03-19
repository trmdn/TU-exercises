#include <stdio.h>

int main() {
    int hours, minutes;

    printf("Vuvedete chas (0-23): ");
    scanf("%d", &hours);
    printf("Vuvedete minuti (0-59): ");
    scanf("%d", &minutes);

    minutes += 15;

    if (minutes >= 60){
        hours += 1;
        minutes -= 60;
    }

    if (hours >= 24){
        hours = 0;
    }

    printf("Chasut sled 15 minuti shte bude: %d:%02d\n", hours, minutes);

    return 0;
}