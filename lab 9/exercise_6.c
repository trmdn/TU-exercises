#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n){
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n;
    printf("Vuvedete broy elementi (N): ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *primes = (int *)malloc(n * sizeof(int));
    int arr_size = 0;
    int prime_size = 0;

    printf("Vuvedete %d chisla:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int current_idx = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(arr[i])){
            primes[prime_size++] = arr[i];
        } else{
            arr[current_idx++] = arr[i];
        }
    }
    arr_size = current_idx;

    printf("\nMasiv s ne-prosti chisla:\n");
    for(int i = 0; i < arr_size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nMasiv s prosti chisla:\n");
    for(int i = 0; i < prime_size; i++){
        printf("%d ", primes[i]);
    }

    free(arr);
    free(primes);

    return 0;
}