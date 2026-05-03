#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char expiry_date[9];
    long long product_code;
    float price;
    int quantity;
} Medicine;

int is_expired(const char *expiry, const char *target){
    int m1, y1, m2, y2;
    sscanf(expiry, "%d.%d", &m1, &y1);
    sscanf(target, "%d.%d", &m2, &y2);

    if (y1 < y2) return 1;
    if (y1 == y2 && m1 < m2) return 1;
    return 0;
}

Medicine* get_expired_medicines(Medicine *arr, int size, const char *search_date, int *result_count){
    int count = 0;
    for(int i = 0; i < size; i++){
        if (is_expired(arr[i].expiry_date, search_date)){
            count++;
        }
    }

    if (count == 0){
        *result_count = 0;
        return NULL;
    }

    Medicine *result = (Medicine *)malloc(count * sizeof(Medicine));
    if (result == NULL) return NULL;

    int j = 0;
    for(int i = 0; i < size; i++){
        if (is_expired(arr[i].expiry_date, search_date)){
            result[j++] = arr[i];
        }
    }

    *result_count = count;
    return result;

}

int save_offer_to_text_file(Medicine *arr, int size, float min_price, float max_price){
    FILE *txt_fp = fopen("offer.txt", "w");

    if(txt_fp == NULL){
        perror("Greshka pri suzdavane na offer.txt");
        return 0;
    }

    int saved_count = 0;

    for(int i = 0; i < size; i++){
        // Proverka dali cenata e v diapazona
        if (arr[i].price >= min_price && arr[i].price <= max_price){

            // Zaposvame dannite v ukazaniq format
            // <ime> <data> <kod> <cena>

            fprintf(txt_fp, "%s %s %lld %.2f\n",
                    arr[i].name, arr[i].expiry_date, arr[i].product_code, arr[i].price);
            saved_count++;
        }
    }

    fclose(txt_fp);

    return saved_count;
}

// FUNKCIQ SAMO ZA TEST (Suzdava binaren file)

void prepared_file(){
    FILE *f = fopen("medicine.bin", "wb");
    Medicine data[3] = {
        {"Aspirin", "10.2025",1111111111111LL, 5.50, 100},
        {"Analgin", "02.2024", 2222222222222LL, 3.20, 50},
        {"Vitamin-C", "12.2026", 3333333333333LL, 12.00, 200}
    };

    fwrite(data, sizeof(Medicine), 3, f);
    fclose(f);
}

void deleted_medicine(Medicine *arr, int *size, const char *target_name, const char *target_date){
    int found = 0;

    for(int i = 0; i < *size; i++){
        if (strcmp(arr[i].name, target_name) == 0 && strcmp(arr[i].expiry_date, target_date) == 0){

            for(int j = 0; j < *size; i++){
                arr[j] = arr[j + 1];
            }

            (*size)--;
            found = 1;
            i--;

            printf("Lekarstvoto '%s' (%s) beshe iztrito uspeshno.\n", target_name, target_date);
        }
    }

    if(!found){
        printf("Greshka! Ne e namereno lekarstvo s ime '%s' i data '%s'.\n", target_name, target_date);
    }
}

int main(){
    prepared_file();

    // NACHALO NA PURVA ZADACHA
    FILE *fp = fopen("medicine.bin", "rb");
    if (fp == NULL){
        perror("Greshka pri otvarqne na file-a");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    int total_medicines = file_size / sizeof(Medicine);
    if (total_medicines == 0){
        printf("Tozi file e prazen\n");
        fclose(fp);
        return 0;
    }

    Medicine *medicines = (Medicine *)malloc(total_medicines * sizeof(Medicine));
    fread(medicines, sizeof(Medicine), total_medicines, fp);
    fclose(fp);
    // KRAY NA PURVA ZADACHA

    // NACHALO NA VTORA ZADACHA

    int expired_count = 0;
    char search_date[9] = "05.2026";

    Medicine *expired_list = get_expired_medicines(medicines, total_medicines, search_date, &expired_count);

    if(expired_list != NULL){
        printf("Namereni sa %d lekarstva s iztichasht srok predi %s.\n");

        for(int i = 0; i < expired_count; i++){
            printf("Lekarstvo: %s, Kod:%lld\n", expired_list[i].name, expired_list[i].product_code);
        }

        free(expired_list);
    } else {
        printf("Nqma lekarstva, koito da otgovarqt na uslovieto.\n");
    }

    // KRAY NA VTORA ZADACHA

    // NACHALO NA TRETA ZADACHA

    float min_p = 5.0, max_p = 50.0; 
    int saved = save_offer_to_text_file(medicines, total_medicines, min_p, max_p);

    if(saved > 0){
        printf("Uspeshno zapisani %d oferti v offer.txt\n", saved);
    } else{
        printf("Nqma lekarstva v cenoviq diapazon %.2f - %.2f euro.\n", min_p, max_p);
    }

    // CHETVURTA ZADACHA 
    char del_name[31] = "Aspirin";
    char del_date[8] = "12.2025";

    free(medicines);
    return 0;
}