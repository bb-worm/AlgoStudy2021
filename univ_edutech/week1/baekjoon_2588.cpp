#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int tmp_b = b;
    while (tmp_b > 0) {
        printf("%d\n", a * (tmp_b%10));
        tmp_b /= 10;
    }
    printf("%d\n", a*b);
}