#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define PI 3.14


// (Zadacha 1) Geometrichni figuri

void geometryTask() {
    int choice;
    float a, b, h, r, l1, l2;
    printf("\n--- (Zadacha 1) Izberete Figura ---\n");
    printf("1-Kvadrat, 2-Pravougulnik, 3-Triugulnik, 4-Krug, 5-Trapec: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        printf("Vuvedi strana: "); scanf("f", &a);
        printf("Kvadrat | Lice: %.2f | Obikolka: %.2f\n", a*a, 4*a);
        break;
    case 2:
        printf("Vuvedete a, b: "); scanf("%f %f", &a, &b);
        printf("Pravougulnik | Lice: %.2f | Obikolka: %.2f\n", a*b, 2*(a+b));
        break;
    case 3:
        printf("Vuvedete a, b, c i visochina h_a"); scanf("%f %f %f %f", &a, &b, &l1, &h);
        printf("Triugulnik | Lice: %.2f | Obikolka: %.2f\n", (a*h)/2, a+b+l1);
        break;
    case 4:
        printf("Radius"); scanf("%f", &r);
        printf("Okrujnost | Lice: %.2f | Obikolka: %.2f\n", PI*r*r, 2*PI*r);
        break;
    case 5:
        printf("Osnovi a, b, bedra c, d, visochina h: "); scanf("%f %f %f %f %f", &a, &b, &l1, &l2, h);
        printf("Trapec | Lice: %.2f | Obikolka: %.2f\n", ((a+b)*h)/2, a+b+l1+l2);
        break;
    default:
        printf("Nevaliden izbor!");
    }
}


// (Zadacha 2) Masiv

void reverseArray(int arr[], int n) {
    for(int i = 0; i < n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

void arrayTask() {
    int n;
    printf("\n--- (Zadacha 2) Masiv ---\n Broy elementi N: ");
    scanf("%d", &n);
    int arr[n], sum = 0, evenCount = 0;

    printf("Vuvedete %d chisla: ", n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int max = arr[0], min = arr[0];

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
        if(arr[i] % 2 == 0) evenCount++;
    }
    printf("Suma %d | Max: %d | Min: %d | Chetni: %d\n", sum, max, min, evenCount);
    reverseArray(arr, n);
    printf("Oburnat masiv: ");
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

// (Zadacha 3) Rabota s chislo

bool isPrime(int n) {
    if (n <= 1){
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
        else{
            return true;
        }
    }
}

void numberStatsTask(){
    int n, temp, sum = 0, count = 0, rev = 0;
    printf("\n--- (Zadacha 3) Rabota s chislo ---\nVuvedete polojitelno chislo: ");
    scanf("%d", &n);

    temp = n;
    while(temp > 0){
        int digit = temp % 10;
        sum += digit;
        rev = rev * 10 + digit;
        count++;
        temp /= 10;
    }

    printf("Prosto: %s | Suma tsifri: %d | Broy tsifri: %d | Oburnato: %d\n",
         isPrime(n) ? "Da": "Ne", sum, count, rev);
}

// (Zadacha 4) Menyu s Operacii - Kalkulator

int gcd(int a, int b){
    while (b) {
        a %= b; int t = a; a = b; b = t;
    }
    return a;
}

void calculatorTask(){
    int op;
    double a, b;
    printf("\n--- (Zadacha 4) Menyu Operacii ---\n1-Subirane , 2-Izvajdane, 3-Umnojenie, 4-Delenie, 5-Stepen, 6-NOD: ");
    scanf("%d", &op);
    printf("Vuvedete dve chisla: ");
    scanf("%f %f", &a, &b);

    switch (op)
    {
    case 1:
        printf("Rezultat: %.2f\n", a + b);
        break;
    case 2:
        printf("Rezultat: %.2f\n", a - b);
        break;
    case 3:
        printf("Rezultat: %.2f\n", a * b);
        break;
    case 4:
        if (b != 0) { printf("Rezultat: %.2f", a / b); }
        else { printf("Greshka: delenie na 0!\n"); }
        break;
    case 5:
        printf("Rezultat: %.2f", pow(a, b));
        break;
    case 6:
        printf("NOD: %d\n", gcd((int)a, (int)b));
        break;
    
    default:
        printf("Nevalidna opciq!\n");
        break;
    }
}

// (Zadacha 5) Rabota s tekst

void stringTask(){
    char str[101];
    int upper = 0, lower = 0, digits = 0;
    printf("\n--- (Zadacha 5) Tekst ---\nVuvedete tekst: ");
    getchar();
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;

    int len = strlen(str);
    bool isPalin = true;

    for(int i = 0; i < len; i++){
        if(isupper(str[i])) upper++;
        if(islower(str[i])) lower++;
        if(isdigit(str[i])) digits++;
        if(i < len/2 && str[i] != str[len-1-i]) isPalin = false;
    }
    printf("Duljina: %d | Glavni: %d | Malki: %d | Tsifri: %d | Palindrom: %s\n",
          len, upper, lower, digits, isPalin ? "Da" : "Ne");
}


// Main Function

int main() {
    int choice;

    while (1) {
        printf("\n==========================\n");
        printf("       SELECT A TASK      \n");
        printf("==========================\n");
        printf("1-5: Run Exercise\n");
        printf("0:    Exit Program\n");
        printf("--------------------------\n");
        printf("Your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }

        if (choice == 0) {
            printf("Exiting... Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:geometryTask(); break;
            case 2:arrayTask(); break;
            case 3:numberStatsTask(); break;
            case 4: calculatorTask(); break;
            case 5: stringTask(); break;
            default: printf("No such task! Try again.\n");
        }
    }

    return 0;
}