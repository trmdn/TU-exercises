#include <stdio.h>
#include <math.h>

int main(){
    int numbers[7];
    int sum = 0;
    float average;

    printf("Vuvedete 7 chisla v intervala [-5000...5000]:\n");

    for (int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = (float)sum / 7;
    printf("Sredna stoynost: %.2f\n", average);

    int closest_num = numbers[0];
    int position = 0;

    float min_diff = fabs(numbers[0] - average);

    for(int i = 1; i < 7; i++){
        float current_diff = fabs(numbers[i] - average);

        if (current_diff < min_diff){
            min_diff = current_diff;
            closest_num = numbers[i];
            position = i;
        }
    }
    
    printf("Nay blizkoto chislo e: %d\n", closest_num);
    printf("Namira se na poziciq (index): %d\n", position);

    return 0;
}