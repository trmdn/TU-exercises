#include <stdio.h>
#include <limits.h>

int main(){
    int N, M;

    printf("Vuvedete broy redove (N) i broy koloni (M): ");
    scanf("%d %d", &N, &M);

    int matrix[N][M];

    printf("Vuvedete elementite na matricata: ");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    long max_sum = LONG_MIN;
    int target_value = 0;
    int best_row = 0, best_col = 0;

    // Obhojdane na vseki element
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            long current_sum = 0;



            for (int row_offset = -1; row_offset <= 1; row_offset++){
                for (int col_offset = -1; col_offset <= 1; col_offset++){
                    int row = i + row_offset;
                    int col = j + col_offset;

                    if(row >= 0 && row < N && col >= 0 && col < M){
                        current_sum += matrix[row][col];
                    }
                }
            }
            
            if(current_sum > max_sum){
            max_sum = current_sum;
            target_value = matrix[i][j];
            best_row = i;
            best_col = j;
            }
        }

    }

    printf("\nChisloto s nay-gloqm sbor ot susedite e: %d\n", target_value);
    printf("Poziciq: [%d, %d]\n", best_row, best_col);
    printf("Sumata na susedite mu e: %ld\n", max_sum);

    return 0;
}