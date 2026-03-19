#include <stdio.h>

int main() {
    int points;
    double bonus = 0.0;

    printf("Vuvedete nachalen broy tochki: ");
    scanf("%d", &points);

    if (points <= 100){
        bonus = 5;
    }
    else if (points > 1000){
        bonus = points * 0.10;
    }
    else {
        bonus = points * 0.20;
    }

    if (points % 2 == 0){
        bonus += 1;
    }
    else if (points % 10 == 5){
        bonus += 2;
    }

    printf("Bonus tochki: %.1f\n", bonus);
    printf("Obsht broy tochki: %.1f\f", points + bonus);

    return 0;
}