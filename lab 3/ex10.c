#include <stdio.h>

int main(){
    int n, number;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

    printf("Vuvedete broy chisla: ");
    if (scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden broy chisla");
        return 1;
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
    return 0;
}