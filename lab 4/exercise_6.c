#include <stdio.h>

int main(){
    int n;
    printf("Vuvedete N: ");
    scanf("%d", &n);

    if (n <= 0) return 0;

    int a[n];
    printf("Vuvedete elementite:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int max_len = 1;
    int current_len = 1;
    int max_end_idx = 0;

    for (int i = 1; i < n; i++){
        if (a[i] > a[i - 1]){
            current_len++;
        }
        else {
            if (current_len > max_len){
                max_len = current_len;
                max_end_idx = i - 1;
            }
            current_len = 1;
        }
    }

    printf("\nNay-dulga narastvashta podredica (duljina %d):\n", max_len);
    int start_idx = max_end_idx - max_len + 1;
    for (int i = start_idx; i <= max_end_idx; i++){
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}