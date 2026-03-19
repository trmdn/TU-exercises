#include <stdio.h>
#include <string.h>

int main(){
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
    return 0;
}