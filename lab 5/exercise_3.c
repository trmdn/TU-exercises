#include <stdio.h>

int main(){
    int numbers[7];
    int sum = 0;
    float average;

    printf("Vuvedete celi chisla v intervala [-5000...5000]: \n");

    for (int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = (float)sum/7;

    printf("\nSredna stoynost: %.2f\n", average);

    return 0;
}