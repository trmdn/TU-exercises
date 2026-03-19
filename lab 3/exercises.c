#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>

// EXERCISE 1

int getMax(int a, int b){
    return (a > b) ? a : b;
}

int getMin(int a, int b){
    return (a < b) ? a : b;
}

void exercise_1() {
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
}


// EXERCISE 2

void exercise_2() {
    int hours, minutes;

    printf("Vuvedete chas (0-23): ");
    scanf("%d", &hours);
    printf("Vuvedete minuti (0-59): ");
    scanf("%d", &minutes);

    minutes += 15;

    if (minutes >= 60){
        hours += 1;
        minutes -= 60;
    }

    if (hours >= 24){
        hours = 0;
    }

    printf("Chasut sled 15 minuti shte bude: %d:%02d\n", hours, minutes);
}


// EXERCISE 3

void exercise_3() {
    double num1, num2, num3;

    printf("Vuvedete tri chisla (razdeleni s interval): ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if (num1 == num2 && num2 == num3){
        printf("Vsichki chisla sa ednakvi!");
    }
    else {
        printf("Chislata sa razlichni");
    }
}


// EXERCISE 4

void exercise_4() {
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

}


// EXERCISE 5

void exercise_5() {
    int time1, time2, time3;
    int totalSeconds, minutes, seconds;

    printf("Vuvedete vremenata na trimata sustezateli (1-50 sek.):\n");
    scanf("%d %d %d", &time1, &time2, &time3);

    totalSeconds = time1+ time2 + time3;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;

    printf("Obshto vreme: %d:%02d\n", minutes, seconds);

}


// EXERCISE 6

void exercise_6() {
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

}


// EXERCISE 7

void exercise_7(){
    int n;
    char period[10];
    double totalPrice = 0.0;

    printf("Vuvedete razstoqnie v km: ");
    scanf("%d", &n);
    printf("Vuvedete period (day/night): ");
    scanf("%s", period);

    if (n >= 100){
        totalPrice = n * 0.06;
    }
    else if (n >= 20){
        totalPrice = n * 0.09;
    }
    else {
        double startFee = 0.70;
        if (strcmp(period, "day") == 0){
            totalPrice = startFee + (n * 0.79);
        }
        else {
            totalPrice = startFee + (n * 0.90);
        }
    }

    printf("Nay niskata cena: %.2f lv.\n", totalPrice); 
}


// EXERCISE 8

void exercise_8(){
    int v, p1, p2;
    double h;

    printf("Obem na baseyna (V): ");
    scanf("%d", &v);
    printf("Debit na purva truba (P1); ");
    scanf("%d", &p1);
    printf("Debit na vtora truba");
    scanf("%d", &p2);
    printf("Chasove otsustvie (H): ");
    scanf("%lf", &h);

    double waterFromP1 = p1 * h;
    double waterFromP2 = p2 * h;
    double totalWater = waterFromP1 + waterFromP2;

    if (totalWater <= v){
        int totalPercent = (int)(totalWater / v * 100);
        int p1Percent = (int)(waterFromP1 / totalWater * 100);
        int p2Percent = (int)(waterFromP2 / totalWater * 100);

        printf("Baseynut e pulen %d%%. Truba 1: %d%%. Truba 2: %d%%.\n", 
            totalPercent, p1Percent, p2Percent);
    }
    else {
        double overflow = totalWater - v;
        printf("Za %.2f chasa baseynut shte se prepulni s %.2f litra.\n", h, overflow);
    }

}


// EXERCISE 9

void exercise_9() {
    int x, y, z, workers;

    printf("Plosht na lozeto (X kv.m): ");
    scanf("%d", &x);
    printf("Grozde ot kv.m (Y kg): ");
    scanf("%d", &y);
    printf("Jelano kolichestvo vino (Z litra): ");
    scanf("%d", &z);
    printf("Broy rabotnici: ");
    scanf("%d", &workers);

    double totalGrape = x * y;
    double grapeForWine = totalGrape * 0.40;
    double producedWine = grapeForWine / 2.5;

    if (producedWine >= z){
        double remainingWine = producedWine - z;
        double winePerWorker = remainingWine / workers;
        printf("Good harvest this year! Total wine: %.0f liters.\n", floor(producedWine));
        printf("%.0f liters left -> %.0f liters per person.\n", ceil(remainingWine), ceil(winePerWorker));

    }
    else {
        double neededWine = z - producedWine;
        printf("It will be a tough winter! More %.0f liters wine needed.\n", floor(neededWine));
    }
}


// EXERCISE 10

void exercise_10(){
    int n, number;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

    printf("Vuvedete broy chisla: ");
    if (scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden broy chisla");
        //return 1;
    }

    printf("Vuvedete %d chisla:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &number);

        if (number < 200){
            c1++;
        }
        else if (number >= 200 && number <= 399){
            c2++;
        }
        else if (number >= 400 && number <= 599){
            c3++;
        }
        else if (number >= 600 && number <= 799){
            c4++;
        }
        else {
            c5++;
        }
    }

    printf("%.2f%%\n", (c1 * 100) / n);
    printf("%.2f%%\n", (c2 * 100) / n);
    printf("%.2f%%\n", (c3 * 100) / n);
    printf("%.2f%%\n", (c4 * 100) / n);
    printf("%.2f%%\n", (c5 * 100) / n);
}


// EXERCISE 11

void exercise_11(){
    int n;
    printf("Vuvedete n: ");
    scanf("%d", &n);

    int colSize = n / 2;
    int midSize = 2 * n - 2 * colSize - 4;

    printf("/");
    for (int i = 0; i < colSize; i++) printf("^");
    printf("\\");

    if (midSize > 0) {
        for (int i = 0; i < midSize; i++) printf("_");
    }

    printf("/");
    for (int i = 0; i < colSize; i++) printf("^");
    printf("\\\n");

    for (int row = 0; row < n - 2; row++){
        printf("|");

        if (row == n - 3 && midSize > 0){
            for (int i = 0; i < colSize + 1; i++) printf(" ");
            for (int i = 0; i < midSize; i++) printf("_");
            for (int i = 0; i < colSize + 1; i++) printf(" ");
        } else {
            for (int i = 0; i < 2 * n - 2; i++) printf(" ");
        }

        printf("|\n");
    }

    printf("\\");
    for (int i = 0; i < colSize; i++) printf("_");
    printf("/");

    if (midSize > 0){
        for (int i = 0; i < midSize; i++) printf(" ");
    }

    printf("\\");
    for(int i = 0; i < colSize; i++) printf("_");
    printf("/\n");
}

// EXERCISE 12

void exercise_12(){
    int n;
    printf("Vuvedete n: ");
    scanf("%d", &n);

    int width = 2 * n - 1;
    int halfWidth = n - 1;
    int sideRows = n - 2;

    for (int i = 0; i < sideRows; i++){
        if (i % 2 == 0){
            for (int j = 0; j < halfWidth - 1; j++) printf("*");
            printf("\\ /");
            for(int j = 0; j < halfWidth - 1; j++) printf("*");
        } else {
            for (int j = 0; j < halfWidth - 1; j++) printf("-");
            printf("\\ /");
            for (int j = 0; j < halfWidth - 1; j++) printf("-");
        }
        printf("\n");
    }

    for (int i = 0; i < halfWidth; i++) printf(" ");
    printf("@\n");

    for (int i = 0; i < sideRows; i++) {
        if (i % 2 == 0){
            for (int j = 0; j < halfWidth - 1; j++) printf("*");
            printf("/ \\");
            for (int j = 0; j < halfWidth - 1; j++) printf("*");
        } else {
            for (int j = 0; j < halfWidth - 1; j++) printf("-");
            printf("/ \\");
            for (int j = 0; j < halfWidth - 1; j++) printf("-");
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n==========================\n");
        printf("       SELECT A TASK      \n");
        printf("==========================\n");
        printf("1-12: Run Exercise\n");
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
            case 1: exercise_1(); break;
            case 2: exercise_2(); break;
            case 3: exercise_3(); break;
            case 4: exercise_4(); break;
            case 5: exercise_5(); break;
            case 6: exercise_6(); break;
            case 7: exercise_7(); break;
            case 8: exercise_8(); break;
            case 9: exercise_9(); break;
            case 10: exercise_10(); break;
            case 11: exercise_11(); break;
            case 12: exercise_12(); break;
            default: printf("No such task! Try again.\n");
        }
    }

    return 0;
}