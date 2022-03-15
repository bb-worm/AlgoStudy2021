#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


void bfs(int idx, const vector<vector<int>> computers, unordered_set<int>& visit) {
    queue<int> q;
    q.push(idx);
    visit.insert(idx);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i=0; i<computers[0].size(); i++) {
            if (visit.find(i) != visit.end()) // already visit
                continue;
            if (computers[now][i] == 0) // not connected
                continue;
            q.push(i);
            visit.insert(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    unordered_set<int> visit;

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (visit.find(i) != visit.end())
            continue;
        bfs(i, computers, visit);
        cnt++;
    }
    return cnt;
}

int main() {
    int n = 3;
    vector<vector<int>> computers = {{1, 1, 0}, 
                                     {1, 1, 0}, 
                                     {0, 0, 1}};
    int ans = solution(n, computers);
    cout << ans;
}