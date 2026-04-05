#include <stdio.h>

void reverse(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int n, k;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0) return 1;

    int arr[n];

    printf("Vuvedete %d celi chisla:\n ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Vuvedete pozicii za otmestvane (K): ");
    scanf("%d ", &k);

    k = k % n;
    if (k < 0){
        k = k + n;
    }

    // Obrushtame celiq masiv
    reverse(arr, 0, n - 1);
    //Obrushtame k elementa 
    reverse(arr, 0, k - 1);
    //Obrushtame ostanalite N-K elementa
    reverse(arr, k, n - 1);

    printf("\nMasivut sled otmestvane s %d pozicii:\n", k);
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}