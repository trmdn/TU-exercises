#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

//EXERCISE 1
#define MAX_N 100
#define MAX_M 100

// EXERCISE 4
#define MAX 100001
int friends_count[MAX];

// EXERCISE 5
#define MAX_SIZE 10000
int element[MAX_SIZE];
int count = 0;

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

// EXERCISE 6
int isPrime(int n){
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

// FUNCTIONS

void exercise_1(){
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

}

void exercise_2(){
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

}

void exercise_3(){
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

}

void exercise_4(){
    int N, M;

    if(scanf("%d %d", &N, &M) != 2) return 0;

    for(int i = 0; i <= N; i++){
        friends_count[i] = 0;
    }

    for(int i = 0; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        if(a >= 1 && a <= N) friends_count[a]++;
        if(b >= 1 && b <= N) friends_count[b]++; 
    }

    int query_person;
    printf("Vuvedete nomer na chovek za spravka: ");
    if(scanf("%d", &query_person) == 1){
        if(query_person >= 1 && query_person <= N){
            printf("Chovekut %d ima %d priqteli", query_person, friends_count[query_person]);
        } else{
            printf("Nevaliden nomer na chovek");
        }
    }

}


// EXERCISE 5
void add(int x){
    if (count < MAX_SIZE){
        element[count++] = x;
        printf("Dobaveno: %d\n", x);
    }
}

void delete_element(int x){
    int found = 0;
    int new_count = 0;
    for(int i = 0; i < count; i++){
        if(element[i] == x){
            element[new_count++] = element[i];
        } else{
            found = 1;
        }
    }
    if(found){
        printf("Izstriti sa vsichki sreshtaniq na: %d\n", x);
    } else{
        printf("Elementut %d ne e nameren.\n", x);
    }
    count = new_count;
}

void smallest(int x){
    if(x > 0 && x <= count){
        qsort(element, count, sizeof(int), compare);
        printf("%d-toto nay-malko chislo e: %d\n", x, element[x-1]);
    } else{
        printf("Greshka: nqma nalichni %d elementa.\n", x);
    }
}

void exercise_5(){
    int choice, x;

    printf("Komandi: 1: add(x) 2: delete(x) 3: smallest(x) 0: exit\n");

    while(1){
        printf("\nIzberete komanda:");
        scanf("%d", &choice);
        if(choice == 0) break;

        switch (choice)
        {
        case 1: add(x); break;
        case 2: delete_element(x); break;
        case 3: smallest(x); break;
        default: printf("Nevalidna komanda!\n");
        }
    }

}

void exercise_6(){
    int n;
    printf("Vuvedete broy elementi (N): ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *primes = (int *)malloc(n * sizeof(int));
    int arr_size = 0;
    int prime_size = 0;

    printf("Vuvedete %d chisla:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int current_idx = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(arr[i])){
            primes[prime_size++] = arr[i];
        } else{
            arr[current_idx++] = arr[i];
        }
    }
    arr_size = current_idx;

    printf("\nMasiv s ne-prosti chisla:\n");
    for(int i = 0; i < arr_size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nMasiv s prosti chisla:\n");
    for(int i = 0; i < prime_size; i++){
        printf("%d ", primes[i]);
    }

    free(arr);
    free(primes);

}

void exercise_7(){
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
}

void exercise_8(){
    int current_size = 10;

    int *arr = (int *)malloc(current_size * sizeof(int));

    if(arr == NULL){
        printf("Greshka pri zadelqne na pamet!\n");
        return 1;
    }

    printf("Vuvedete 10 nachalni chisla:\n");
    for(int i = 0; i < current_size; i++){
        scanf("%d", &arr[i]);
    }

    int value, position;
    printf("Vuvejdayte 'chislo' i 'poziciq' (0 za kray):\n");

    while(1){
        if (scanf("%d", &value) != 1 || value == 0) break;
        scanf("%d", &position);
        if(position < 0 || position > current_size){
            printf("Nevalidna poziciq!\n");
            continue;
        }
        current_size++;
        arr = (int *)realloc(arr, current_size * sizeof(int));

        for (int i = current_size - 1; i > position; i--){
            arr[i] = arr[i - 1];
        }

        arr[position] = value;
    }
    
    printf("\nIzhod: ");
    for(int i = 0; i < current_size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

int main(){
    int choice;

    while (1) {
        printf("\n==========================\n");
        printf("       SELECT A TASK      \n");
        printf("==========================\n");
        printf("1-8: Run Exercise\n");
        printf("Note: Number 4 is bonus exercise");
        printf("0:    Exit Program\n");
        printf("--------------------------\n");
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1){
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        if (choice == 0){
            printf("Exiting... Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: exercise_1(); break;
            case 2: exercise_2(); break;
            case 3: exercise_3(); break;
            case 4: exercise_4(); break;
            case 5: exercise_5(); break;
            case 6: exercise_6(); break;
            case 7: exercise_7(); break;
            case 8: exercise_8(); break;
            default: printf("No such task! Try again.\n");
        }
    }

    return 0;
}