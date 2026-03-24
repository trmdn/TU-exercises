#include <stdio.h>

int main(){
    int n;

    printf("Vuvedete broq na elementite N: ");
    if(scanf("%d", &n) != 1 || n <= 0){
        printf("Nevaliden razmer. \n");
        return 1;
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

    return 0;
}