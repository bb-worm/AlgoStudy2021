#include <stdio.h>

bool is_leap_year(int year) {
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    else if (year % 400 == 0)
        return true;
    return false;
}

int main() {
    int year;
    scanf("%d", &year);

    if (is_leap_year(year))
        printf("1");
    else
        printf("0");
}