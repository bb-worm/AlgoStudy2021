#include <iostream>
#include <vector>

using namespace std;


int main() {
    // bool: 1 byte
    // bool[1,000]: 1KB
    // bool[1,000,000]: 1MB
    bool is_exist[2000001] = {false, };

    int N;
    scanf("%d", &N);

    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        is_exist[num] = true;
    }

    int target;
    scanf("%d", &target);

    int ans = 0;
    for (int i=0; i<=target/2; i++) {
        if (is_exist[i] && is_exist[target-i]) {
            if (i == target-i)
                continue;
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}