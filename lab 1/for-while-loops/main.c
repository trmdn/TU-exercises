#include <stdio.h>

// If-Else
// Task 1
void exercise_1() {
    int number;
    printf("{Task 1} Enter a number: ");
    scanf("%d", &number);
    if (number > 6) {
        printf("The number is greater than 6\n");
    }
}

// Task 2
void exercise_2() {
    int number;
    printf("{Task 2} Enter a number: ");
    scanf("%d", &number);
    if (number % 8 > 4) {
        printf("The remainder of %d divided by 8 is greater than 4\n", number);
    }
}

// Task 3
void exercise_3() {
    int a, b, c;
    printf("{Task 3} Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    printf("The smallest number is %d\n", min);
}

// Task 4
void exercise_4() {
    int digit;
    printf("{Task 4} Enter a digit (0-9): ");
    scanf("%d", &digit);
    printf("The name of the digit is: ");
    switch (digit) {
    case 0: printf("zero\n"); break;
    case 1: printf("one\n"); break;
    case 2: printf("two\n"); break;
    case 3: printf("three\n"); break;
    case 4: printf("four\n"); break;
    case 5: printf("five\n"); break;
    case 6: printf("six\n"); break;
    case 7: printf("seven\n"); break;
    case 8: printf("eight\n"); break;
    case 9: printf("nine\n"); break;
    default: printf("This is not a digit!\n");
    }
}

// Task 5
void exercise_5() {
    int day;
    printf("{Task 5} Enter a number for the day of the week (1-7): ");
    scanf("%d", &day);

    switch (day) {
    case 1: printf("Monday\n"); break;
    case 2: printf("Tuesday\n"); break;
    case 3: printf("Wednesday\n"); break;
    case 4: printf("Thursday\n"); break;
    case 5: printf("Friday\n"); break;
    case 6: printf("Saturday\n"); break;
    case 7: printf("Sunday\n"); break;
    default: printf("Invalid number! Enter a number from 1 to 7\n"); break;
    }
}

// For-While Loops
// Task 6
void exercise_6() {
    int n;
    printf("{Task 6} Enter a number for the pyramid: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i = i + 1) {
        for (int j = 1; j <= i; j = j + 1) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

// Task 7
void exercise_7() {
    int a, b, sum = 0;
    printf("{Task 7} Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int little, big;
    if (a < b) {
        little = a;
        big = b;
    } else {
        little = b;
        big = a;
    }
    for (int i = little + 1; i < big; i = i + 1) {
        sum = sum + i;
    }
    printf("The sum between them is %d\n", sum);
}

// Task 8
void exercise_8() {
    int a, b, suma_chetni = 0;
    long long proiz_nechetni = 1;
    printf("{Task 8} Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int malko, golyamo;
    if (a < b) { malko = a; golyamo = b; }
    else { malko = b; golyamo = a; }

    for (int i = malko + 1; i < golyamo; i = i + 1) {
        if (i % 2 == 0) {
            suma_chetni = suma_chetni + i;
        } else {
            proiz_nechetni = proiz_nechetni * i;
        }
    }
    printf("Sum of even: %d, Product of odd: %lld\n", suma_chetni, proiz_nechetni);
}

// Task 9
void exercise_9() {
    int n, k, chislo, broyach = 0;
    printf("{Task 9} Enter N and K: ");
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i = i + 1) {
        printf("Enter a number: ");
        scanf("%d", &chislo);
        if (chislo > k && chislo % 3 == 0) {
            broyach = broyach + 1;
        }
    }
    printf("Result: %d numbers\n", broyach);
}

// Task 10
void exercise_10() {
    int n, suma = 0;
    printf("{Task 10} Enter numbers (0 to end):\n");
    do {
        scanf("%d", &n);
        suma = suma + n;
    } while (n != 0);
    printf("Total sum: %d\n", suma);
}

// Task 11
void exercise_11() {
    double start, end;
    printf("{Task 11} Enter start and end of interval: ");
    scanf("%lf %lf", &start, &end);
    
    // Ensuring the loop direction
    double s = (start < end) ? start : end;
    double e = (start > end) ? start : end;

    printf(" x \t | f(x)\n");
    printf("-------------------\n");
    for (double x = s; x <= e; x = x + 0.01) {
        double y = x * x - 4;
        printf("%.2f \t | %.4f\n", x, y);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n==========================\n");
        printf("       SELECT A TASK      \n");
        printf("==========================\n");
        printf("1-11: Run Exercise\n");
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
            case 1:  exercise_1();  break;
            case 2:  exercise_2();  break;
            case 3:  exercise_3();  break;
            case 4:  exercise_4();  break;
            case 5:  exercise_5();  break;
            case 6:  exercise_6();  break;
            case 7:  exercise_7();  break;
            case 8:  exercise_8();  break;
            case 9:  exercise_9();  break;
            case 10: exercise_10(); break;
            case 11: exercise_11(); break;
            default: printf("No such task! Try again.\n");
        }
    }

    return 0;
}