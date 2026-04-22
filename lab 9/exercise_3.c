#include <stdio.h>
#include <limits.h>

int main(){
    int N, M;

    printf("Vuvedete broy redove (N) i broy koloni (M): ");
    if(scanf("%d %d", &N, &M) != 2) return 1;

    int matrix[N][M];

    printf("Vuvedete elementite na matricata: ");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int min_row_index = 0;
    int max_row_index = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (matrix[i][j] < min_val){
                min_val = matrix[i][j];
                min_row_index = i;
            }
            if (matrix[i][j] > max_val){
                max_val = matrix[i][j];
                max_row_index = i;
            }
        }
    }

    if (min_row_index != max_row_index){
        for(int j = 0; j < M; j++){
            int temp = matrix[min_row_index][j];
            matrix[min_row_index][j] = matrix[max_row_index][j];
            matrix[max_row_index][j] = temp;
        }
        printf("\nRedovete %d i %d bqhva razmeneni.\n", min_row_index, max_row_index);
    } else{
        printf("\n Nay malkiqt i nay_golemiqt index sa na edin i sushti red. Nqma nujda ot razmqna");
    }

    printf("\n--- Rezultat na matrica ---");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%d ", matrix[i][j]);
        } 
        printf("\n");
    }

    return 0;
}