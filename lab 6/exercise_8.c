#include <stdio.h>

#define MAX_SIZE 20

int main(){
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
        printf("%d ", arr[i]);
    }
    printf("\n");

    if(count == MAX_SIZE){
        printf("Masivut e zapulen.\n");
    }

    return 0;
}