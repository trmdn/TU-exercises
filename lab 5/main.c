#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// EXERCISE 3
#define MAX_WORD_LEN 51


// EXERCISE 2

typedef struct
{
    char name[50];
    float price;
    int id;
    int quantity;
} Product;

typedef struct
{
    char address[100];
    int product_id;
    bool is_fulfilled;
} Order;

Product products[100];
int product_count = 0;

Order waiting_orders[100];
int order_count = 0;


void check_waiting_orders(int product_index){
    for (int i = 0; i < order_count; i++){
        if (!waiting_orders[i].is_fulfilled && waiting_orders[i].product_id == products[product_index].id){
            if (products[product_index].quantity > 0){
                printf("Client %s ordered %s\n", waiting_orders[i].address, products[product_index].name);
                products[product_index].quantity--;
                waiting_orders[i].is_fulfilled = true;
            }
        }
    }
}


void exercise_1(){
    int numbers[7];
    int sum = 0;

    printf("Vuvedete celi chisla v intervala [-5000...5000]: \n");

    for(int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    printf("\nIzhod: %d\n", sum);
}


void exercise_2(){
    int numbers[7];
    int max;

    printf("Vuvedete celi chisla v intervala [-5000...5000]: \n");

    for(int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
    }

    max = numbers[0];

    for (int i = 1; i < 7; i++){
        if (numbers[i] > max){
            max = numbers[i];
        }
    }

    printf("\nIzhod: %d\n", max);

}


void exercise_3(){
    int numbers[7];
    int sum = 0;
    float average;

    printf("Vuvedete celi chisla v intervala [-5000...5000]: \n");

    for (int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = (float)sum/7;

    printf("\nSredna stoynost: %.2f\n", average);

}


void exercise_4(){ 
    int numbers[7];
    int sum = 0;
    float average;

    printf("Vuvedete 7 chisla v intervala [-5000...5000]:\n");

    for (int i = 0; i < 7; i++){
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = (float)sum / 7;
    printf("Sredna stoynost: %.2f\n", average);

    int closest_num = numbers[0];
    int position = 0;

    float min_diff = fabs(numbers[0] - average);

    for(int i = 1; i < 7; i++){
        float current_diff = fabs(numbers[i] - average);

        if (current_diff < min_diff){
            min_diff = current_diff;
            closest_num = numbers[i];
            position = i;
        }
    }
    
    printf("Nay blizkoto chislo e: %d\n", closest_num);
    printf("Namira se na poziciq (index): %d\n", position);

}


// BONUS EXERCISES


// EXERCISE 1

void bonus_exercise_1(){
    int guests;
    char input[20];

    float price_chair = 13.99;
    float price_table = 42.00;
    float price_cups = 5.98;
    float price_dishes = 21.02;

    int bought_chairs = 0, bought_tables = 0, bought_cups_sets = 0, bought_dishes_sets = 0;
    float total_spent = 0;
    
    if(scanf("%d", &guests) != 1);

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
}


// EXERCISE 2


void bonus_exercise_2(){
    char command[20];

    while (1){
        scanf("%s", command);

        if (strcmp(command, "END") == 0){
            break;
        }

        if (strcmp(command, "Product") == 0){
            char name[50];
            float price;
            int id;
            scanf("%s %f %d", name, &price, &id);

            // Check if product exists on list
            int found_idx = -1;
            for (int i = 0; i < product_count; i++){
                if (products[i].id == id){
                    found_idx = i;
                    break;
                }
            }

            if (found_idx != -1){
                products[found_idx].quantity++;
                check_waiting_orders(found_idx);
            } else {
                strcpy(products[product_count].name, name);
                products[product_count].price = price;
                products[product_count].id = id;
                products[product_count].quantity = 1;
                product_count++;
                check_waiting_orders(product_count - 1);
            }
        } else if (strcmp(command, "Order") == 0){
            char address[100];
            int product_id;
            scanf("%s %d", address, &product_id);

            bool executed = false;

            for (int i = 0; i < product_count; i++){
                if (products[i].id == product_id && products[i].quantity > 0){
                    printf("Client %s ordered %s\n", address, products[i].name);
                    products[i].quantity--;
                    executed = true;
                    break;
                }
            }

            if(!executed){
                strcpy(waiting_orders[order_count].address, address);
                waiting_orders[order_count].product_id = product_id;
                waiting_orders[order_count].is_fulfilled = false;
                order_count++;
            }
        }
    }
}

// EXERCISE 3

void bonus_exercise_3(){
    FILE *txtFile = fopen("input.txt", "r");
    if(!txtFile){
        printf("Greshka pri otvarqne na input.txt\n");
    }

    char **selectedWords = NULL;
    int count = 0;
    char currentWord[MAX_WORD_LEN];
    char lastChar = '\0';

    while (fscanf(txtFile, "%s", currentWord) == 1){
        if (count == 0 || currentWord[0] == lastChar){
            selectedWords = (char **)realloc(selectedWords, (count + 1) * sizeof(char *));
            selectedWords[count] = malloc(strlen(currentWord) + 1);
            strcpy(selectedWords[count], currentWord);

            lastChar = currentWord[strlen(currentWord) - 1];
            count++;
        }
    }
    fclose(txtFile);

    FILE *binFileOut = fopen("output.bin", "wb");
    if (!binFileOut){
        printf("Greshka pri suzdavane na binarniq file!\n");
    }

    for (int i = 0; i < count; i++){
        fwrite(selectedWords[i], sizeof(char), strlen(selectedWords[i]), binFileOut);
        if (i < count - 1){
            char space = ' ';
            fwrite(&space, sizeof(char), 1, binFileOut);
        }
        free(selectedWords[i]);
    }
    free(selectedWords);
    fclose(binFileOut);


    printf("Sudurjanie na binarniq file:\n");
    FILE *binFileIn = fopen("output.bin", "rb");
    if(!binFileIn);

    char ch;
    while (fread(&ch, sizeof(char), 1, binFileIn) == 1){
        printf("%c", ch);
    }
    printf("\n");
    fclose(binFileIn);

}


int main(){
    int choice;

    while (1) {
        printf("\n==========================\n");
        printf("       SELECT A TASK      \n");
        printf("==========================\n");
        printf("1-4: Run Exercise\n");
        printf("5-n: Run Bonus Exercises\n");
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
            // BONUS EXERCISES
            case 5: bonus_exercise_1(); break;
            case 6: bonus_exercise_2(); break;
            case 7: bonus_exercise_3(); break;
            default: printf("No such task! Try again.\n");
        }
    }

    return 0;
}