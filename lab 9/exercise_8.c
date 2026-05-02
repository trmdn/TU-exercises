#include <stdio.h>
#include <stdlib.h>

int main(){
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


    return 0;
}