#include <stdio.h>

int main() {
    double x1, y1, x2, y2, x, y;

    printf("Vuvedete x1, y1 (goren lqv ugul): \n");
    scanf("%lf %lf", &x1, &y1);
    printf("Vuvedete x2, y2 (dolen desen ugul): \n");
    scanf("%lf %lf", &x2, &y2);
    printf("Vuvedete koordinatite na tochkata (x, y): \n");
    scanf("%lf %lf", &x, &y);

    if (x >= x1 && x <= x2 && y >= y1 && y <= y2){
        printf("Inside\n");
    }
    else {
        printf("Outside\n");
    }

    return 0;
}