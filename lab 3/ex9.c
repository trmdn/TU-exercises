#include <stdio.h>
#include <math.h>

int main() {
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

    return 0;
}

