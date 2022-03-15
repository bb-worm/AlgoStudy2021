#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N;
vector<vector<int>> island(100, vector<int>(100));

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool check_range(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= N)
        return false;
    return true;
}

int BFS2(int i, int j) {
    int number = island[i][j];

    queue<pair<int, int>> q;
    vector<vector<int>> visit(N, vector<int>(N, -1));
    q.push({i, j});
    visit[i][j] = 0;

    int y, x, ny, nx;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int k=0; k<4; k++) {
            ny = y + dy[k];
            nx = x + dx[k];

            if (!check_range(ny, nx) || island[ny][nx] == number || visit[ny][nx] != -1)
                continue;

            // other land
            if (island[ny][nx] != 0 && island[ny][nx] != number) {
                return visit[y][x];
            }

            q.push({ny, nx});
            visit[ny][nx] = visit[y][x] + 1;
        }
    }
    return -1;
}

// 주변이 0이라고 외곽이 아니었음
// BFS2가 -1을 뱉는다는 건 외곽이 아니었다는 의미
int find_shortest_bridge(vector<pair<int, int>> edges) {
    int ans = N * N;

    for (auto& p : edges) {
        int m = BFS2(p.first, p.second);
        if (m != -1 && m < ans)
            ans = m;
    }

    return ans;
}

void BFS(int i, int j, int number) {
    queue<pair<int, int>> q;
    q.push({i, j});
    island[i][j] = number;

    int y, x, ny, nx;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int k=0; k<4; k++) {
            ny = y + dy[k];
            nx = x + dx[k];

            if (!check_range(ny, nx) || island[ny][nx] == 0 || island[ny][nx] == number)
                continue;
            
            q.push({ny, nx});
            island[ny][nx] = number;
        }
    }
}

vector<pair<int, int>> find_edges() {
    vector<pair<int, int>> edges;
    int y, x;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (island[i][j] == 0)
                continue;

            bool isEdge = false;
            for (int k=0; k<4; k++) {
                y = i + dy[k];
                x = j + dx[k];

                if (!check_range(y, x))
                    continue;

                if (island[y][x] == 0)
                    isEdge = true;
            }
            if (isEdge)
                edges.push_back({i, j});
        }
    }
    return edges;
}

void numbering_island() {
    int number = 2;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (island[i][j] == 1) {
                BFS(i, j, number);
                number++;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &island[i][j]);
        }
    }
    
    numbering_island();
    auto edges = find_edges();
    int ans = find_shortest_bridge(edges);
    cout << ans << endl;
}