#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    int next = num;
    int cnt = 0;
    while (true) {
        cnt++;
        next = (next%10)*10 + (next/10 + next%10)%10;

        if (num == next)
            break;
    }
    printf("%d", cnt);
}