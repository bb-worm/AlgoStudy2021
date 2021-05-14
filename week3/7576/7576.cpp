#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int> > box;

void set_input() {
    ios_base::sync_with_stdio(0);
    cin >> M >> N;
    box.reserve(N);
    for (int i=0; i<N; i++) {
        box[i].reserve(M);
        for (int j=0; j<M; j++){
            cin >> box[i][j];
        }
    }
}

int bfs() {
    queue<pair<int, int> > q;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (box[i][j] == 1)
                q.push(make_pair(i, j));

    int days = -1;
    int r, c;
    int nr, nc;
    int size;
    while (!q.empty()) {
        days += 1;
        size = q.size();

        for (int s=0; s<size; s++) {
            r = q.front().first;
            c = q.front().second;
            q.pop();

            for (int i=0; i<4; i++) {
                nr = r + dr[i];
                nc = c + dc[i];
                if (nr<0 || nr>=N || nc<0 || nc>=M || box[nr][nc]!=0)
                    continue;
                q.push(make_pair(nr, nc));
                box[nr][nc] = 1;
            }
        }
    }
    return days;
}

bool zero_tomato_exist() {
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (box[i][j] == 0)
                return true;
    return false;
}

int main() {
    set_input();
    int days = bfs();
    if (zero_tomato_exist())
        cout << -1;
    else
        cout << days;
}