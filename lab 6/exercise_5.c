#include <stdio.h>

int main(){
    int n, k;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer!");
        return 0;
    }

    int arr[n];

    printf("Vuvedete %d celi chisla:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Vuvedete K (koy po golemina element tursim): ");
    if(scanf("%d", &k) != 1 || k <= 0 || k > n){
        printf("Nevalidna stoynost za K. Trqbva da e mejdu 1 i %d.\n", n);
        return 1;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(arr[j] < arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\n%d-tiqt po golemina element e: %d\n", k, arr[k - 1]);

    return 0;
}