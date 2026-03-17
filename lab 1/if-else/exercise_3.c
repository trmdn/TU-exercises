#include <stdio.h>

int main() {
    int a, b, c;
    printf("Въведи три числа: ");
    scanf("%d %d %d", &a, &b, &c);
    int min = a;
    if (b < min){
        min = b;
    }
    if (c < min) {
        min = c;
    }
    printf("Най-малкото число е %d\n", min);
    return 0;
}