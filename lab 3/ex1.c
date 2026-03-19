#include <stdio.h>
#include <limits.h>

int getMax(int a, int b){
    return (a > b) ? a : b;
}

int getMin(int a, int b){
    return (a < b) ? a : b;
}

int main() {
    int number;
    int maxSoFar = INT_MIN;
    int minSoFar = INT_MAX;
    int count = 0;
    
    printf("Vuvejdayte chisla (0 za kray)\n");

    while (1){
        printf("Chislo: ");
        scanf("%d", &number);

        if (number == 0){
            break;
        }

        maxSoFar = getMax(maxSoFar, number);
        minSoFar = getMin(minSoFar, number);
        count++;
    }

    if (count > 0){
        printf("\n--- Rezultati ---\n");
        printf("Nay-golqmoto chislo: %d\n", maxSoFar);
        printf("Nay-malkoto chislo: %d\n", minSoFar);
    }
    else {
        printf("Ne ste vuveli nikakvi chisla osven 0.\n");
    }
    return 0;
}