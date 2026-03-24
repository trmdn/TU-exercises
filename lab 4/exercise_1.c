#include <stdio.h>

int main(){
    int n;

    printf("Vuvedete broq na elementite N: ");
    if (scanf("%d", &n) != 1 || n <= 0){
        printf("Nevalidno chislo\n");
        return 1;
    }

    int arr[n];
    printf("Vuvedete elementite na masiva (sortirani): \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int current_start = 0;
    int current_len = 1;

    int max_start = 0;
    int max_len = 1;

    for (int i = 1; i < n; i++){
        if (arr[i] == arr[i - 1]){
            current_len++;
        }
        else {
            if (current_len > max_len){
                max_len = current_len;
                max_start = current_start;
            }
            current_start = i;
            current_len = 1;
        }
    }

    if (current_len > max_len){
        max_len = current_len;
        max_start = current_start;
    }

    printf("\nNay dulgata ploshtadka zapochva ot indeks: %d\n", max_start);
    printf("Duljina: %d\n", max_len);
    printf("Element na ploshtada: %d\n", arr[max_start]);

    return 0;
}