#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int N;
vector<vector<int>> height;
bool height_exist[101] = {false, };

int get_safe_area(int h);
void BFS(int i, int j, int h, bool visit[][101]);

int main() {
    // input
    cin >> N;
    for (int i=0; i<N; i++) {
        vector<int> tmp;
        int h;
        for (int j=0; j<N; j++) {
            cin >> h;
            tmp.push_back(h);
            height_exist[h] = true;
        }
        height.push_back(tmp);
    }

    int ans = 1; // 처음에 0으로 해서 틀렸음
    for (int i=1; i<=100; i++) {
        // no i height
        if (!height_exist[i])
            continue;
        ans = max(ans, get_safe_area(i));
    }
    cout << ans << endl;
}

int get_safe_area(int h) {
    int total_safe_area = 0;
    bool visit[101][101] = {false, };
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (height[i][j] > h && !visit[i][j]) {
                BFS(i, j, h, visit);
                total_safe_area++;
            }
        }
    }
    return total_safe_area;
}

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int i, int j, int h, bool visit[][101]) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visit[i][j] = true;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        int ny, nx;
        for (int k=0; k<4; k++) {
            ny = now.first + dy[k];
            nx = now.second + dx[k];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;
            if (visit[ny][nx])
                continue;
            if (height[ny][nx] <= h)
                continue;

            q.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
}