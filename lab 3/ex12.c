#include <stdio.h>

int main(){
    int n;
    printf("Vuvedete n: ");
    scanf("%d", &n);

    int width = 2 * n - 1;
    int halfWidth = n - 1;
    int sideRows = n - 2;

    for (int i = 0; i < sideRows; i++){
        if (i % 2 == 0){
            for (int j = 0; j < halfWidth - 1; j++) printf("*");
            printf("\\ /");
            for(int j = 0; j < halfWidth - 1; j++) printf("*");
        } else {
            for (int j = 0; j < halfWidth - 1; j++) printf("-");
            printf("\\ /");
            for (int j = 0; j < halfWidth - 1; j++) printf("-");
        }
        printf("\n");
    }

    for (int i = 0; i < halfWidth; i++) printf(" ");
    printf("@\n");

    for (int i = 0; i < sideRows; i++) {
        if (i % 2 == 0){
            for (int j = 0; j < halfWidth - 1; j++) printf("*");
            printf("/ \\");
            for (int j = 0; j < halfWidth - 1; j++) printf("*");
        } else {
            for (int j = 0; j < halfWidth - 1; j++) printf("-");
            printf("/ \\");
            for (int j = 0; j < halfWidth - 1; j++) printf("-");
        }
        printf("\n");
    }
    return 0;
}