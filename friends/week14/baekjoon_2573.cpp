#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map;
queue<pair<int, int>> ice_loca;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void print_map() {
    printf("\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            printf("%d ", map[i][j]);
        }printf("\n");
    }printf("\n");
}

void melt() {
    vector<vector<int>> old_map;
    old_map = map;

    int size = ice_loca.size();
    for (int i=0; i<size; i++) {
        pair<int, int> ice = ice_loca.front();
        ice_loca.pop();

        int total_zero = 0;
        int ny, nx;
        for (int i=0; i<4; i++) {
            ny = ice.first + dy[i];
            nx = ice.second + dx[i];
            if (old_map[ny][nx] <= 0)
                total_zero++;
        }
        if (map[ice.first][ice.second] - total_zero <= 0) {
            map[ice.first][ice.second] = 0;
        } else {
            map[ice.first][ice.second] -= total_zero;
            ice_loca.push(ice);
        }
    }
}

// bfs
bool check_split() {
    if (ice_loca.empty())
        return false;

    queue<pair<int, int>> q;
    bool visit[301][301] = {false, };
    
    q.push(ice_loca.front());
    visit[q.front().first][q.front().second] = true;
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        int ny, nx;
        for (int i=0; i<4; i++) {
            ny = now.first + dy[i];
            nx = now.second + dx[i];
            if (visit[ny][nx] || map[ny][nx] == 0)
                continue;
            q.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }

    // 방문하지 않은 곳이 있으면 나눠졌다는 의미
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j] != 0 && !visit[i][j])
                return true;
        }
    }
    return false;
}

int min_year() {
    int year = 0;
    while (!ice_loca.empty()) {
        year++;
        melt();
        // print_map();
        if (check_split())
            return year;    
        // print_map();
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i=0; i<N; i++) {
        vector<int> tmp;
        int num;
        for (int j=0; j<M; j++) {
            scanf("%d", &num);
            tmp.push_back(num);
            if (num != 0)
                ice_loca.push(make_pair(i, j));
        }
        map.push_back(tmp);
    }

    int ans = min_year();
    printf("%d\n", ans);
}