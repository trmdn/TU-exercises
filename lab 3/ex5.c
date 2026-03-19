#include <stdio.h>


int main() {
    int time1, time2, time3;
    int totalSeconds, minutes, seconds;

    printf("Vuvedete vremenata na trimata sustezateli (1-50 sek.):\n");
    scanf("%d %d %d", &time1, &time2, &time3);

    totalSeconds = time1+ time2 + time3;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;

    printf("Obshto vreme: %d:%02d\n", minutes, seconds);

    return 0;
}