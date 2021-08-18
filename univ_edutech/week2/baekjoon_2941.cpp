#include <stdio.h>
#include <string.h>

int main() {
    char str[101];
    scanf("%s", str);

    int cnt = 0;
    int size = strlen(str);
    for (int i=0; i<size; i++) {
        cnt++;
        if (i+1 >= size) {
            continue;
        }

        char now = str[i];
        char next = str[i+1];

        if (now == 'd' && next == 'z' && i+2 < size && str[i+2] == '=') {
            i += 2;
        } else if ((now == 'c' || now == 'd') && next == '-') {
            i += 1;
        } else if ((now == 'l' || now == 'n') && next == 'j') {
            i += 1;
        } else if ((now == 'c' || now == 's' || now == 'z') && next == '=') {
            i += 1;
        }
    }
    printf("%d\n", cnt);
}