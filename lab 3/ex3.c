#include <stdio.h>


int main() {
    double num1, num2, num3;

    printf("Vuvedete tri chisla (razdeleni s interval): ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if (num1 == num2 && num2 == num3){
        printf("Vsichki chisla sa ednakvi!");
    }
    else {
        printf("Chislata sa razlichni");
    }
    return 0;
}