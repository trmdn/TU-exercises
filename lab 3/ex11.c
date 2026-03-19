#include <stdio.h>

int main(){
    int n;
    printf("Vuvedete n: ");
    scanf("%d", &n);

    int colSize = n / 2;
    int midSize = 2 * n - 2 * colSize - 4;

    printf("/");
    for (int i = 0; i < colSize; i++) printf("^");
    printf("\\");

    if (midSize > 0) {
        for (int i = 0; i < midSize; i++) printf("_");
    }

    printf("/");
    for (int i = 0; i < colSize; i++) printf("^");
    printf("\\\n");

    for (int row = 0; row < n - 2; row++){
        printf("|");

        if (row == n - 3 && midSize > 0){
            for (int i = 0; i < colSize + 1; i++) printf(" ");
            for (int i = 0; i < midSize; i++) printf("_");
            for (int i = 0; i < colSize + 1; i++) printf(" ");
        } else {
            for (int i = 0; i < 2 * n - 2; i++) printf(" ");
        }

        printf("|\n");
    }

    printf("\\");
    for (int i = 0; i < colSize; i++) printf("_");
    printf("/");

    if (midSize > 0){
        for (int i = 0; i < midSize; i++) printf(" ");
    }

    printf("\\");
    for(int i = 0; i < colSize; i++) printf("_");
    printf("/\n");
    return 0;
}
