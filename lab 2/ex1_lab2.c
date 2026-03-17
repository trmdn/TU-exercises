#include <stdio.h>
#include <math.h>

// const na PI
#define PI 3.14

float areaSquare(float a){
    return a * a;
}

float areaRectangle(float a, float b){
    return a * b;
}

float areaTriangle(float a, float b){
    return (a * b) / 2.0;
}

float areaCircle(float r){
    return PI * r * r;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void checkEvenOdd(int n){
    if (n * 2 == 0){
        printf("Chisloto %d e chetno.\n", n);
    }
    else {
        printf("Chisloto %d e nechetno.\n", n);
    }
}

void decToBinary(int n){
    if (n == 0){
        printf("0");
        return;
    }
    int binary[32];
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    printf("Dvoichno predstavqne: ");
    for (int j = i - 1; j >= 0; j--){
        printf("%d", binary[j]);
    }
    printf("\n");
}


int main(){
    int choice;
    float a, b, r;

    printf("--- Izchislqvane na lice ---\n");
    printf("Izberete figura (1-Kvadrat, 2-Pravougulnik, 3-Triugulnik, 4-Krug): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Vuvedete strana: "); scanf("%f", &a);
        printf("Tip: Kvadrt | Lice: %.2f\n", areaSquare(a));
        break;
    case 2:
        printf("Vuvedete dve strani: "); scanf("%f %f", &a, &b);
        printf("Tip: Pravougulnik | Lice: %.2f\n", areaRectangle(a, b));
        break;
    case 3:
        printf("Vuvedete dva kateta: "); scanf("%f %f", &a, &b);
        printf("Tip: Pravougulen Triugulnik | Lice: %.2f\n", areaTriangle(a, b));
        break;
    case 4:
        printf("Vuvedete radius: "); scanf("%f", &r);
        printf("Tip: Okrujnost | Lice: %.2f\n", areaCircle(r));
        break;
    
    default:
        printf("Nevaliden Kod!");
    }

    printf("--- Demonstaciq na dopulneni funkcii ---\n");

    int num1= 10, num2 = 20;
    printf("Predi razmqna: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("Sled razmqna: num1 = %d, num2 = %d\n", num1, num2);

    checkEvenOdd(num1);
    decToBinary(13);

    return 0;
}