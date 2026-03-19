#include <stdio.h>

int main(){
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

    return 0;
}