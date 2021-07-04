#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int> > map;
int ans = -1;
vector<pair<int, int> > virus;
int total_safe;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void set_input();
void set_wall(int, int, int);
int bfs();

int main() {
    ios_base::sync_with_stdio(0);
    set_input();
    set_wall(0, 0, 0);
    cout << ans;
}

void set_input() {
    total_safe = 0;
    cin >> N >> M;
    map.reserve(N);
    int num;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> num;
            map[i].push_back(num);
            if (num == 2)
                virus.push_back(make_pair(i, j));
            else if (num == 0)
                total_safe++;
        }
    }
}

void set_wall(int r, int c, int set_num) {
    if (set_num == 3) {
        ans = max(ans, bfs());
        return;
    }

    if (r >= N)
        return;
    if (c >= M) {
        set_wall(r+1, 0, set_num);
        return;
    }

    if (map[r][c] == 0) {
        map[r][c] = 1;
        set_wall(r, c+1, set_num + 1);
        map[r][c] = 0;
    }
    set_wall(r, c+1, set_num);
}

int bfs() {
    queue<pair<int, int> > q;
    for (int i=0; i<virus.size(); i++) {
        q.push(make_pair(virus[i].first, virus[i].second));
    }
    int n_map[N][M];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            n_map[i][j] = map[i][j];
        }
    }
    int safe_zone = total_safe - 3;
    
    int r, c;
    int nr, nc;
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            if (nr<0 || nc<0 || nr>=N || nc>=M)
                continue;
            if (n_map[nr][nc] != 0)
                continue;
            n_map[nr][nc] = 2;
            q.push(make_pair(nr, nc));
            safe_zone--;
            if (safe_zone <= ans) {
                return safe_zone;
            }
                
        }
    }
    return safe_zone;
}