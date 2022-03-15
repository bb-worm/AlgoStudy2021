#include <iostream>
#include <vector>

using namespace std;


bool check_num(int guess, vector<pair<int, pair<int, int>>> queries) {
    // check guess
    int g1 = guess / 100;
    int g2 = guess / 10 % 10;
    int g3 = guess % 10;
    if (g1 == g2 || g1 == g3 || g2 == g3)
        return false;
    if (g1 == 0 || g2 == 0 || g3 == 0)
        return false;

    int num, strike, ball;
    int n1, n2, n3;
    for (auto& query : queries) {
        num = query.first;
        n1 = num / 100;
        n2 = num / 10 % 10;
        n3 = num % 10;

        // cal strike & ball
        strike = ball = 0;
        if (g1 == n1) strike++;
        if (g2 == n2) strike++;
        if (g3 == n3) strike++;
        if (g1 == n2 || g1 == n3) ball++;
        if (g2 == n1 || g2 == n3) ball++;
        if (g3 == n1 || g3 == n2) ball++;

        if (strike != query.second.first || ball != query.second.second)
            return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, pair<int, int>>> queries;
    for (int i=0; i<N; i++) {
        int num, strike, ball;
        cin >> num >> strike >> ball;
        queries.push_back({num, {strike, ball}});
    }

    int ans = 0;
    for (int i=111; i<=999; i++) {
        if (check_num(i, queries))
            ans++;
    }
    cout << ans;
}