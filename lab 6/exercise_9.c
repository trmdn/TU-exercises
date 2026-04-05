#include <stdio.h>

int main(){
    int n;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer");
        return 1;
    }

    int arr[n];

    printf("Vuvedete %d chisla:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int current_len = 1;
    int max_len = 1;
    int max_value = arr[0];

    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1]){
            current_len++;
        } else{
            current_len = 1;
        }

        if(current_len > max_len){
            max_len = current_len;
            max_value = arr[i];
        }
    }

    printf("\nIzhod: ");
    for(int i = 0; i < max_len; i++){
        printf("%d", max_value);
    }
    printf("\n");

    return 0;
}