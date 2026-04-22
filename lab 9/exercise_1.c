#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100
#define MAX_M 100

int main(){
    int N, M;
    int matrix[MAX_N][MAX_M];
    bool rows_ok = true;
    bool cols_ok = true;

    // 1. Vuvejdane na redove i koloni
    printf("Vuvedete broy redove (N) i koloni (M): ");
    scanf("%d %d", &N, &M);

    // 2. Vuvejdane na elementite na matricata
    printf("Vuvedete elementite na matricata: ");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    // 3. Proverka na redovete (za narastvash red: a[j] < a[j + 1] )
    for(int i = 0; i < N; i++){
        for(int j = 0; i < M; j++){
            if(matrix[i][j] > matrix[i][j + 1]){
                rows_ok = false;
                break;
            }
        }
    }

    // 4. Proverka na kolonite (za namalqvasht red: a[i] > a[i + 1])
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matrix[i][j] < matrix[i + 1][j]){
                cols_ok = false;
                break;
            }
        }
    }

    // 5. Rezultat

    printf("\n--- Rezultat ---\n");
    if(rows_ok && cols_ok){
        printf("Uslovieto e izpulneno. Vsichki redova rastat i vsichki koloni namalqvat");
    }
    else{
        if (!rows_ok) printf("Greshka: Ne vseki red e narastvash red.");
        if (!cols_ok) printf("Greshka: Ne vseki red e namalqvasht red.");
    }

    return 0;
}