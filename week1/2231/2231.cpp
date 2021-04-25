#include <iostream>

using namespace std;

bool is_constructor(int, int);

int main() {
    int N;
    cin >> N;

    int digit = 0;
    int tmp = N;
    while (tmp > 0) {
        tmp /= 10;
        digit += 1;
    }

    int ans = 0;
    for (int i=max(1, N - digit*9); i<=N; i++) {
        if (is_constructor(i, N)) {
            ans = i;
            break;
        }
    }
    cout << ans;
}

bool is_constructor(int i, int N) {
    int sum = i;
    while (i > 0) {
        sum += i % 10;
        i /= 10;
        if (sum > N)
            return false;
    }
    return sum == N;
}