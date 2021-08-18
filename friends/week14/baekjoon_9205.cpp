#include <stdio.h>
#include <queue>
#include <math.h>

using namespace std;

const int max_beer = 1000;

int distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool can_go(pair<int, int> start, vector<pair<int, int>> loca, pair<int, int> end) {
    queue<pair<int, int>> q;
    vector<bool> visit(loca.size(), false);
    q.push(start);

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        if (distance(now, end) <= max_beer)
            return true;

        for (int i=0; i<loca.size(); i++) {
            if (visit[i])
                continue;
            if (distance(now, loca[i]) > max_beer)
                continue;
            q.push(loca[i]);
            visit[i] = true;
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i=0; i<T; i++) {
        int n;
        scanf("%d", &n);

        int y, x;
        scanf("%d %d", &y, &x);
        pair<int, int> start = make_pair(y, x);
        
        vector<pair<int, int>> loca;
        for (int j=0; j<n; j++) {
            scanf("%d %d", &y, &x);
            loca.push_back(make_pair(y, x));
        }

        scanf("%d %d", &y, &x);
        pair<int, int> end = make_pair(y, x);

        if (can_go(start, loca, end))
            printf("happy\n");
        else
            printf("sad\n");
    }
}