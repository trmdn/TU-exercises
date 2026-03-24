#include <stdio.h>
#include <stdbool.h>


int main(){
    int n, target_sum;

    printf("Vuvedete broq na elementite N: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int a[n];
    printf("Vuvedete %d elementa:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Vuvedete tursenata suma: ");
    scanf("%d", &target_sum);

    bool found = false;

    for (int start = 0; start < n; start++){
        int current_sum = 0;

        for (int end = start; end < n; end++){
            current_sum += a[end];

            if (current_sum == target_sum){
                printf("\nNamerena posledovatelnost ot indeks %d do %d: ", start, end);
                for (int k = start; k <= end; k++){
                    printf("%d ", a[k]);
                }
                printf("\n");
                found = true;
            }
        }
    }

    if (!found){
        printf("Nqma posledovatelnost s takava suma.\n");
    }

    return 0;
}