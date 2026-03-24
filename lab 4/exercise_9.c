#include <stdio.h>

int main(){
    int n;

    printf("Vuvedete broq na elementite N: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int a[n];
    printf("Vuvedete %d elementa:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int max_len = 1;
    int max_val = a[0];

    int current_len = 1;

    for (int i = 0; i < n - 1; i++){
        if (a[i] == a[i + 1]){
            current_len++;
        } else{
            if (current_len > max_len){
                max_len = current_len;
                max_val = a[i];
            }
            current_len = 1;
        }
    }

    if(current_len > max_len){
        max_len = current_len;
        max_val = a[n - 1];
    }

    printf("Izhod: ");
    for(int i = 0; i < max_len; i++){
        printf("%d ", max_val);
    }
    printf("\n");

    return 0;
}