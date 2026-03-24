#include <stdio.h>

int main(){
    int n, k;

    printf("Vuvedete broq na elementite N: ");
    if(scanf("%d", &n) != 1 || n <= 0) return 1;

    int a[n];
    printf("Vuvedete %d elementa:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Koy pored po golemina element tursim (K): ");
    scanf("%d", &k);

    if(k < 1 || k > n){
        printf("Greshka: K trqbva da e mejdu 1 i %d.\n", n);
        return 1;
    }

    for (int i = 0; i < n - 1; i++){
        int max_idx = 1;
        for (int j = i + 1; j < n; j++){
            if (a[j] > a[max_idx]){
                max_idx = j;
            }
        }
        int temp = a[max_idx];
        a[max_idx] = a[i];
        a[i] = temp;
    }

    printf("%d-tiqt po golemina element e: %d\n", k, a[k - 1]);

    return 0;
}