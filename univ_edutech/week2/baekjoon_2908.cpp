#include <stdio.h>

int main() {
    char a[4], b[4];
    scanf("%s %s", a, b);
    
    char* ans;
    
    for (int i=2; i>=0; i--) {
        if (a[i] > b[i]) {
            ans = a;
            break;
        } else if(a[i] < b[i]) {
            ans = b;
            break;
        }
    }

    for (int i=2; i>=0; i--)
        printf("%c", ans[i]);
}