#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer");
        return 1;
    }

    double a[n];
    bool is_zigzag = true;

    printf("Vuvedete %d elementa: \n", n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &a[i]);
    }
    
    if (n < 2){
        printf("Redicata e tvurde kratka za proverka relacii");
        return 0;
    }

    for (int i = 0; i < n - 1; i++){
        if(i % 2 == 0){
            if(!(a[i] < a[i + 1])){
                is_zigzag = false;
                break;
            }
        } else{
            if(!(a[i] > a[i + 1])){
                is_zigzag = false;
                break;
            }
        }
    }

    if (is_zigzag){
        printf("\nDA, relaciite a0 < a1 > a2 < a3 ... sa izpulneni.\n");
    } else{
        printf("\nNE, relaciite NE sa izpulneni.\n");
    }

    return 0;
}