#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int ans = 0;
vector<pair<int, int> >schedule;
void pick_schedule(int, int);

int main() {

    cin >> N;
    schedule.reserve(N);
    int t, p;
    for (int i=0; i<N; i++) {
        cin >> t >> p;
        schedule.push_back(make_pair(t, p));
    }

    pick_schedule(0, 0);
    cout << ans << endl;
}

void pick_schedule(int idx, int sum) {
    ans = max(ans, sum);
    
    if (idx >= N)
        return;

    int t = schedule[idx].first;
    int p = schedule[idx].second;

    if (idx+t <= N)
        pick_schedule(idx+t, sum+p);
    if (idx+1 <= N)
        pick_schedule(idx+1, sum);
}