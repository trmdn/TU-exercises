#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 20
//EXERCISE 4
void reverse(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


void exercise_1(){
    int n;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer!\n");
        return 1;
    }

    int arr[n];

    printf("Vuvedete %d sortirani chisla:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int current_start = 0;
    int current_len = 1;

    int max_start = 0;
    int max_len = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1]){
            current_len++;
        } else{
            current_start = i;
            current_len = 1;
        }

        if(current_len > max_len){
            max_len = current_len;
            max_start = current_start;
        }
    }

    printf("\n--- Rezultat ---\n");
    printf("Nay dulgata ploshtadka zapochva ot indeks: %d\n", max_start);
    printf("Stoynost na elementite v neq: %d\n", arr[max_start]);
    printf("Duljina na ploshtadkata: %d\n", max_len);

}


void exercise_2(){
    int n;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer");
    }

    double a[n];
    bool is_zigzag = true;

    printf("Vuvedete %d elementa: \n", n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &a[i]);
    }
    
    if (n < 2){
        printf("Redicata e tvurde kratka za proverka relacii");
        return 0;
    }

    for (int i = 0; i < n - 1; i++){
        if(i % 2 == 0){
            if(!(a[i] < a[i + 1])){
                is_zigzag = false;
                break;
            }
        } else{
            if(!(a[i] > a[i + 1])){
                is_zigzag = false;
                break;
            }
        }
    }

    if (is_zigzag){
        printf("\nDA, relaciite a0 < a1 > a2 < a3 ... sa izpulneni.\n");
    } else{
        printf("\nNE, relaciite NE sa izpulneni.\n");
    }
}


void exercise_3(){
    int n;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer.\n");
    }

    int arr[n];

    printf("Vuvedete %d elementa: \n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n / 2; i++){
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("\nOburnat masiv e:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");


}


void exercise_4(){
   int n, k;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0) return 1;

    int arr[n];

    printf("Vuvedete %d celi chisla:\n ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Vuvedete pozicii za otmestvane (K): ");
    scanf("%d ", &k);

    k = k % n;
    if (k < 0){
        k = k + n;
    }

    // Obrushtame celiq masiv
    reverse(arr, 0, n - 1);
    //Obrushtame k elementa 
    reverse(arr, 0, k - 1);
    //Obrushtame ostanalite N-K elementa
    reverse(arr, k, n - 1);

    printf("\nMasivut sled otmestvane s %d pozicii:\n", k);
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}


void exercise_5(){
    int n, k;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer!");
    }

    int arr[n];

    printf("Vuvedete %d celi chisla:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Vuvedete K (koy po golemina element tursim): ");
    if(scanf("%d", &k) != 1 || k <= 0 || k > n){
        printf("Nevalidna stoynost za K. Trqbva da e mejdu 1 i %d.\n", n);
        return 1;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(arr[j] < arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\n%d-tiqt po golemina element e: %d\n", k, arr[k - 1]);
}


void exercise_6(){
    int n;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0);
    
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

}


void exercise_7(){
    int n, target_sum;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0);

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

}


void exercise_8(){
    int arr[MAX_SIZE];
    int count = 0;
    int num, pos;

    printf("Vuvedete 10 chisla:\n");
    for(int i = 0; i < 10; i++){
        if(scanf("%d", &arr[i]) != 1) break;
        count++;
    }

    while (count < MAX_SIZE){
        printf("Vuvedete chislo za vmukvane (ili 0 za kray): ");
        scanf("%d", &num);

        if(num == 0) break;

        printf("Vuvedete indeks (0-%d): ", count);
        scanf("%d", &pos);

        if (pos < 0 || pos > count){
            printf("Nevaliden indeks. Opitayte pak\n");
            continue;
        }

        for(int i = count; i > pos; i--){
            arr[i] = arr[i - 1];
        }

        arr[pos] = num;
        count++;

        printf("Tekusht masiv: ");
        for(int i = 0; i < count; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    printf("\nKraen masiv: ");
    for (int i = 0; i < count; i++){
        printf("%d", arr[i]);
    }
    printf("\n");

    if(count == MAX_SIZE){
        printf("Masivut e zapulen.\n");
    }
}


void exercise_9(){
    int n;

    printf("Vuvedete broq na elementite (N): ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer");
        return 1;
    }

    int arr[n];

    printf("Vuvedete %d chisla:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int current_len = 1;
    int max_len = 1;
    int max_value = arr[0];

    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1]){
            current_len++;
        } else{
            current_len = 1;
        }

        if(current_len > max_len){
            max_len = current_len;
            max_value = arr[i];
        }
    }

    printf("\nIzhod: ");
    for(int i = 0; i < max_len; i++){
        printf("%d", max_value);
    }
    printf("\n");

}

int main(){
    int choice;

    while (1) {
        printf("\n==========================\n");
        printf("       SELECT A TASK      \n");
        printf("==========================\n");
        printf("1-9: Run Exercise\n");
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
            case 9: exercise_9(); break;
            default: printf("No such task! Try again.\n");
        }
    }

    return 0;
}