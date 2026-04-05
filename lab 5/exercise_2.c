#include <stdio.h>

int main(){
    int numbers[7];
    int max;

    printf("Vuvedete celi chisla v intervala [-5000...5000]: \n");

    for(int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
    }

    max = numbers[0];

    for (int i = 1; i < 7; i++){
        if (numbers[i] > max){
            max = numbers[i];
        }
    }

    printf("\nIzhod: %d\n", max);

    return 0;
}