#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > ability;
vector<int> team;
int ans = -1;

void set_and_find_ans(int, int, int);
int get_team_diff();

int main() {
    cin >> N;
    ability.reserve(N*N);
    team.reserve(N);
    int val;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> val;
            ability[i].push_back(val);
        }
        team[i] = 0;
    }

    set_and_find_ans(0, 0, N/2);
    cout << ans << endl;
}

void set_and_find_ans(int idx, int set_num, int limit) {
    if (set_num == limit) {
        int team_diff = get_team_diff();
        if (ans == -1)
            ans = team_diff;
        else
            ans = min(ans, team_diff);
        return;
    }

    if (idx >= N || (N-idx)+set_num < limit)
        return;

    team[idx] = 1;
    set_and_find_ans(idx+1, set_num+1, limit);
    team[idx] = 0;
    set_and_find_ans(idx+1, set_num, limit);
}

int get_team_diff() {
    int team_sum[2] = {0, 0};
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            if (team[i] == team[j]) {
                team_sum[team[i]] += ability[i][j] + ability[j][i];
            }
        }
    }
    return abs(team_sum[0] - team_sum[1]);
}