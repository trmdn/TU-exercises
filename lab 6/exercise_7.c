#include <stdio.h>
#include <stdbool.h>

int main(){
    int n, target_sum;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0) return 1;

    int arr[n];
    printf("Vuvedete %d celi chisla:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Vuvedete tursenata suma: ");
    scanf("%d", &target_sum);

    int current_sum = 0;
    int start = 0;
    bool found = false;

    for(int end = 0; end < n; end++){
        current_sum += arr[end];

        while(current_sum > target_sum && start < end){
            current_sum -= arr[start];
            start++;
        }

        if (current_sum == target_sum){
            printf("\nNamerena posledovatelnost: ");
            for(int i = start; i <= end; i++){
                printf("%d", arr[i]);
                if (i < end) printf(", ");
            }
            printf("\n");
            found = true;
            break;
        }
    }

    if(!found){
        printf("\nNe e namerena posledovatelnost s takava suma.\n");
    }

    return 0;
}