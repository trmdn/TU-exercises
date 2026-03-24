#include <stdio.h>
#include <stdbool.h>

// EXERCISE 1

void exercise_1(){
    int n;

    printf("Vuvedete broq na elementite N: ");
    if (scanf("%d", &n) != 1 || n <= 0){
        printf("Nevalidno chislo\n");
    }

    int arr[n];
    printf("Vuvedete elementite na masiva (sortirani): \n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int current_start = 0;
    int current_len = 1;

    int max_start = 0;
    int max_len = 1;

    for (int i = 1; i < n; i++){
        if (arr[i] == arr[i - 1]){
            current_len++;
        }
        else {
            if (current_len > max_len){
                max_len = current_len;
                max_start = current_start;
            }
            current_start = i;
            current_len = 1;
        }
    }

    if (current_len > max_len){
        max_len = current_len;
        max_start = current_start;
    }

    printf("\nNay dulgata ploshtadka zapochva ot indeks: %d\n", max_start);
    printf("Duljina: %d\n", max_len);
    printf("Element na ploshtada: %d\n", arr[max_start]);
}

// EXERCISE 2

void exercise_2(){
    int n;

    printf("Vuvedete broq na elementite N: ");
    if (scanf("%d", &n) != 1 || n < 2){
        printf("Nevalidno N. Trqbva da ima pone 2 elementa.\n");
    }

    int a[n];
    printf("Vuvedete %d elementa:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    bool is_zigzag = true;

    for (int i = 0; i < n - 1; i++){
        if (i % 2 == 0){
            if(!(a[i] < a[i+1])){
                is_zigzag = false;
                break;
            }
        }
        else {
            if(!(a[i] > a[i+1])){
                is_zigzag = false;
                break;
            }
        }
    }

    if (is_zigzag){
        printf("Relaciite sa izpulneni (Zigzag).\n");
    } else {
        printf("Relaciite ne sa izpulneni.\n");
    }

}

// EXERCISE 3

void exercise_3(){
    int n;

    printf("Vuvedete broq na elementite N: ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer. \n");
    }

    int a[n];
    printf("Vuvedete %d elementa:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n / 2; i++){
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    printf("Oburnat masiv e: \n");
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
    }
    printf("\n");
}

// EXERCISE 4

void exercise_4(){
    int n, k;

    printf("Vuvedete broq na elementite N: ");
    if(scanf("%d", &n) != 1 || n <= 0);

    int a[n], result[n];

    printf("Vuvedete %d elementa:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Vuvevdete broq pozicii za omesvane K: ");
    scanf("%d", &k);

    k = k % n;
    if (k < 0){
        k = n + k;
    }

    for (int i = 0; i < n; i++){
        int new_pos = (i + k) % n;
        result[new_pos] = a[i];
    }

    printf("Masivut sled omestvane s %d pozicii:\n", k);
    for(int i = 0; i < n; i++){
        printf("%d", result[i]);
    }
    printf("\n");
}

// EXERCISE 5

void exercise_5(){
    int n, k;

    printf("Vuvedete broq na elementite N: ");
    if(scanf("%d", &n) != 1 || n <= 0);

    int a[n];
    printf("Vuvedete %d elementa:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Koy pored po golemina element tursim (K): ");
    scanf("%d", &k);

    if(k < 1 || k > n){
        printf("Greshka: K trqbva da e mejdu 1 i %d.\n", n);
    }

    for (int i = 0; i < n - 1; i++){
        int max_idx = 1;
        for (int j = i + 1; j < n; j++){
            if (a[j] > a[max_idx]){
                max_idx = j;
            }
        }
        int temp = a[max_idx];
        a[max_idx] = a[i];
        a[i] = temp;
    }

    printf("%d-tiqt po golemina element e: %d\n", k, a[k - 1]); 
}

// EXERCISE 6

void exercise_6(){
    int n;
    printf("Vuvedete N: ");
    scanf("%d", &n);

    if (n <= 0);

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
}

// EXERCISE 7

void exercise_7(){
    int n, target_sum;

    printf("Vuvedete broq na elementite N: ");
    if (scanf("%d", &n) != 1 || n <= 0);

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
}

// EXERCISE 8

void exercise_8(){
    int arr[20];
    int current_count = 0;
    int num, pos;

    printf("Vuvedete purvonachalnite 10 chisla:\n");
    for(int i = 0; i < 10; i++){
        printf("Chislo %d: ", i + 1);
        scanf("%d", &arr[i]);
        current_count++;
    }

    printf("\nRejim na vmukvane (za spirane vuvedete 0 za chislo):\n");
    while (current_count < 20){
        printf("\nVuvedete chislo za vmukvane: ");
        scanf("%d", &num);

        if (num == 0) break;

        printf("Vuvedete index (0 do %d): ", current_count);
        scanf("%d", &pos);

        if (pos < 0 || pos > current_count){
            printf("Nevaliden index! Opitayte pak.\n");
            continue;
        }

        for (int i = current_count; i > pos; i--){
            arr[i] = arr[i - 1];
        }

        arr[pos] = num;
        current_count++;

        printf("Tekusht masiv: ");
        for(int i = 0; i < current_count; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    if(current_count == 20){
        printf("\nMasivut e zapulnen (20 elementa).\n");
    } else {
        printf("Vuvejdaneto beshe prekrateno ot potrebitelq.\n");
    }

}

// EXERCISE 9

void exercise_9(){
    int n;

    printf("Vuvedete broq na elementite N: ");
    if (scanf("%d", &n) != 1 || n <= 0);

    int a[n];
    printf("Vuvedete %d elementa:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int max_len = 1;
    int max_val = a[0];

    int current_len = 1;

    for (int i = 0; i < n - 1; i++){
        if (a[i] == a[i + 1]){
            current_len++;
        } else{
            if (current_len > max_len){
                max_len = current_len;
                max_val = a[i];
            }
            current_len = 1;
        }
    }

    if(current_len > max_len){
        max_len = current_len;
        max_val = a[n - 1];
    }

    printf("Izhod: ");
    for(int i = 0; i < max_len; i++){
        printf("%d ", max_val);
    }
    printf("\n"); 
}

// BONUS EXERCISE 1
void exercise_1_bonus(){
    int number = 42;
    int *ptr;

    ptr = &number;
    
    printf("--- Demonstraciq na ukazateli ---\n");
    printf("1. Stoynost na promenlivata (number): %d\n", number);
    printf("2. Adres na promenlivata (&number): %p\n", (void*)&number);
    printf("3. Stoynost na ukazatelq (ptr suhranqva adres): %p\n", (void*)ptr);
    printf("4. Stoynost na adresa, kum koyto sochi ukazatelq (*ptr): %d\n", *ptr);

    *ptr = 100;
    printf("\nSled promqna chrez *ptr = 100:\n");
    printf("Novata stoynost na number e: %d\n", number);
}

// BONUS EXERCISE 2

void exercise_2_bonus(){
    double a, b;
    double *p1 = &a;
    double *p2 = &b;

    printf("Vuvedete dve chisla: ");
    scanf("%lf %lf", p1, p2);

    double sum = *p1 + *p2;
    double diff = *p1 - *p2;
    double prod = *p1 * *p2;

    printf("\n--- Rezultati chrez ukazateli ---\n");
    printf("%.2f + %.2f = %.2f\n", *p1, *p2, sum);
    printf("%.2f - %.2f = %.2f\n", *p1, *p2, diff);
    printf("%.2f * %.2f = %.2f\n", *p1, *p2, prod);

    if (*p2 != 0){
        double div = *p1 / *p2;
        printf("%.2f / %.2f = %.2f\n", *p1, *p2, div);
    } else {
        printf("Greshka: Delenie na nula!\n");
    }
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
            case 10: exercise_1_bonus(); break;
            case 11: exercise_2_bonus(); break;
            default: printf("No such task! Try again.\n");
        }
    }

    return 0;
}