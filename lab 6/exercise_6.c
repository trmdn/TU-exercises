#include <stdio.h>

int main(){
    int n;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0) return 1;
    
    int arr[n];
    printf("Vuvedete %d celi chisla:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int current_dec_start = 0, current_dec_len = 1;
    int max_dec_start = 0, max_dec_len = 1;

    int current_inc_start = 0, current_inc_len = 1;
    int max_inc_start = 0, max_inc_len = 1;

    for (int i = 1; i < n; i++){
        if(arr[i] > arr[i - 1]){
            current_inc_len++;
        } else{
            current_inc_start = i;
            current_inc_len = 1;
        }
        if (current_inc_len > max_inc_len){
            max_inc_len = current_inc_len;
            max_inc_start = current_inc_start;
        }

        if (arr[i] < arr[i - 1]){
            current_dec_start;
        } else{
            current_dec_start = i;
            current_dec_len = 1;
        }
        
        if (current_dec_len > max_dec_len){
            max_dec_len = current_dec_len;
            max_dec_start = current_dec_start;
        }
    }

    int final_start, final_len;
    char type[20];

    if (max_inc_len >= max_dec_len){
        final_start = max_inc_start;
        final_len = max_inc_len;
        sprintf(type, "narastvashta");
    } else {
        final_start = max_dec_start;
        final_len = max_dec_len;
        sprintf(type, "namalqvashta");
    }

    printf("\nNay dulgata monotonna podredica e %s.\n", type);
    printf("Duljina: %d\n", final_len);
    printf("Elementi: ");
    for(int i = final_start; i < final_start + final_len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}