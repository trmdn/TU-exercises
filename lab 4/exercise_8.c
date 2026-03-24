#include <stdio.h>

int main(){
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

    return 0;
}