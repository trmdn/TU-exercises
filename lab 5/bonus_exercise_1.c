#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int guests;
    char input[20];

    float price_chair = 13.99;
    float price_table = 42.00;
    float price_cups = 5.98;
    float price_dishes = 21.02;

    int bought_chairs = 0, bought_tables = 0, bought_cups_sets = 0, bought_dishes_sets = 0;
    float total_spent = 0;
    
    if(scanf("%d", &guests) != 1) return 1;

    while (1){
        scanf("%s", input);
        if (strcmp(input, "PARTY!") == 0) break;
        if (strcmp(input, "Chair") == 0) {
            bought_chairs++;
            total_spent += price_chair;
        } else if(strcmp(input, "Table") == 0){
            bought_tables++;
            total_spent += price_table;
        } else if(strcmp(input, "Cups") == 0){
            bought_cups_sets++;
            total_spent += price_cups;
        } else if(strcmp(input, "Dishes") == 0){
            bought_dishes_sets++;
            total_spent += price_dishes;
        }
    }

    int needed_tables = (int)ceil((double)guests / 8);
    int needed_cups_sets = (int)ceil((double)guests / 6);
    int needed_dishes_sets = (int)ceil((double)guests / 6);

    printf("%.2f\n", total_spent);

    if (needed_tables > bought_tables){
        printf("%d Table \n", needed_tables - bought_tables);
    }
    if (guests > bought_chairs){
        printf("%d Chairs \n", guests - bought_chairs);
    }
    if (needed_cups_sets > bought_cups_sets){
        printf("%d Cups \n", needed_cups_sets - bought_cups_sets);
    }
    if (needed_dishes_sets > bought_dishes_sets){
        printf("%d Dishes \n", needed_dishes_sets - bought_dishes_sets);
    }

    return 0;
}