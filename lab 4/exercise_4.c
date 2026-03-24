#include <stdio.h>

int main(){
    int n, k;

    printf("Vuvedete broq na elementite N: ");
    if(scanf("%d", &n) != 1 || n <= 0) return 1;

    int a[n], result[n];

    printf("Vuvedete %d elementa:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Vuvevdete broq pozicii za omesvane K: ");
    scanf("%d", &k);

    k = k % n;
    if (k < 0){
        k = n + k;
    }

    for (int i = 0; i < n; i++){
        int new_pos = (i + k) % n;
        result[new_pos] = a[i];
    }

    printf("Masivut sled omestvane s %d pozicii:\n", k);
    for(int i = 0; i < n; i++){
        printf("%d", result[i]);
    }
    printf("\n");

    return 0;
}