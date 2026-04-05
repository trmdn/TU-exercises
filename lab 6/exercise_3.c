#include <stdio.h>

int main(){
    int n;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer.\n");
        return 1;
    }

    int arr[n];

    printf("Vuvedete %d elementa: \n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n / 2; i++){
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("\nOburnat masiv e:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}