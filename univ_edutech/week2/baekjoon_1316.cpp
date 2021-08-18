#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int cnt = n;
    for (int i=0; i<n; i++) {
        bool alpha[26] = {false, };
        char str[101];
        scanf("%s", str);
        int size = strlen(str);

        char now = str[0];
        alpha[now - 'a'] = true;
        for (int j=1; j<size; j++) {
            char next = str[j];
            if (now != next) {
                if (!alpha[next - 'a']) {
                    alpha[next - 'a'] = true;
                    now = next;
                }
                else {
                    cnt--;
                    break;
                }
            }
        }
    }
    printf("%d\n", cnt);
}