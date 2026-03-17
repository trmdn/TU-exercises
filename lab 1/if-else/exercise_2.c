#include <stdio.h>

int main() {
    int number;
    printf("Въведи число за проверка на остатък: ");
    scanf("%d", &number);

    if (number % 8 > 4) {
        printf("Остатъкът от делението на %d с 8 е по-голям от 4\n", number);
    }
    return 0;
}