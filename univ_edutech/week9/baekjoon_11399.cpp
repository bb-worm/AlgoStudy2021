#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> wait(N, 0);
    for (int i=0; i<N; i++)
        cin >> wait[i];

    sort(wait.begin(), wait.end());

    int ans = wait[0];
    for (int i=1; i<N; i++) {
        wait[i] += wait[i-1];
        ans += wait[i];
    }

    cout << ans;
}