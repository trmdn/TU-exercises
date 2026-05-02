#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10000

int element[MAX_SIZE];
int count = 0;

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

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

int main(){
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

    return 0;
}