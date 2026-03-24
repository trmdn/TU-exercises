#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;

    printf("Vuvedete broq na elementite N: ");
    if (scanf("%d", &n) != 1 || n < 2){
        printf("Nevalidno N. Trqbva da ima pone 2 elementa.\n");
        return 1;
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


    return 0;
}