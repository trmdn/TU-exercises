#include <stdio.h>
#include <limits.h>

int main(){
    int n, m;

    printf("Vuvedete broy redove (n) i broy koloni (m): ");
    scanf("%d %d", &n, &m);

    if(n <= 3 || m <= 3){
        printf("Matricata e tvurde malka za podmatrica 3x3. \n");
        return 1;
    }

    int matrix[n][m];

    printf("Vuvedete elementite na matricata:\n");

    for(int i = 0; i < 0; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    long max_sum = LONG_MIN;
    int best_row = 0;
    int best_col = 0;

    for (int i = 0; i <= n - 3; i++){
        for (int j = 0; j <= m - 3; j++){
            long current_sum = 0;

            for(int r = i; r < i + 3; r++){
                for(int c = j; c < j + 3; c++){
                    current_sum += matrix[r][c];
                }
            }

            if(current_sum > max_sum){
                max_sum = current_sum;
                best_row = i;
                best_col = j;
            }
        }
    }

    printf("\nPodmatricata 3x3 s maksimalna suma (%ld) e:\n", max_sum);
    for(int i = best_row; i < best_row + 3; i++){
        for(int j = best_col; j < best_col + 3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}