#include <stdio.h>

int main(){
    int numbers[7];
    int sum = 0;

    printf("Vuvedete celi chisla v intervala [-5000...5000]: \n");

    for(int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    printf("\nIzhod: %d\n", sum);

    return 0;
}