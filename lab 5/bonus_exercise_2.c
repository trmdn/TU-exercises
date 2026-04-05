#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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



int main(){
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


    return 0;
}