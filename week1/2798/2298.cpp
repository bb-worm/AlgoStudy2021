#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> cards;
int ans = 0;

void find_max_sum(int, int, int);

int main() {
    // set input
    cin >> N >> M;
    cards.reserve(N);
    int num;
    for (int i=0; i<N; i++) {
        cin >> num;
        cards.push_back(num);
    }

    // find answer
    find_max_sum(0, 0, 0);
    cout << ans;
}

void find_max_sum(int idx, int picked, int sum) {
    if (picked == 3) {
        if (sum <= M)
            ans = max(ans, sum);
        return;
    }
    
    if (idx >= N || sum >= M || ans == M) return;

    find_max_sum(idx+1, picked+1, sum+cards[idx]);
    find_max_sum(idx+1, picked, sum);
}