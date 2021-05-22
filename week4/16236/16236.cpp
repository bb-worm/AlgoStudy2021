#include <iostream>
#include <queue>

using namespace std;

int N;
int ocean[20][20];
int start_r, start_c;
int visit[20][20];

void set_input() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> ocean[i][j];
            if (ocean[i][j] == 9) {
                ocean[i][j] = 0;
                start_r = i;
                start_c = j;
            }
            visit[i][j] = 0;
        }
    }
}

void printVisit() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << visit[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void resetVisit() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            visit[i][j] = 0;
        }
    }
}

int bfs() {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int max_time = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(start_r, start_c));
    visit[start_r][start_c] = 1;

    int r, c;
    int nr, nc;
    int size = 2;
    int eat_num = 0;
    int time = 0;
    while (!q.empty()) {
        int q_size = q.size();
        pair<int, int> next_point = make_pair(-1, -1);
        time++;
        for (int i=0; i<q_size; i++) {
            r = q.front().first;
            c = q.front().second;
            q.pop();

            for (int k=0; k<4; k++) {
                nr = r + dr[k];
                nc = c + dc[k];
                if (nr<0 || nc<0 || nr>=N || nc>=N)
                    continue;
                if (visit[nr][nc] == 1 || ocean[nr][nc] > size)
                    continue;
                if (ocean[nr][nc] != 0 && ocean[nr][nc] < size) { // eat fish
                    if (next_point.first==-1 || next_point.first > nr || (next_point.first==nr && next_point.second>nc)){
                        next_point.first = nr;
                        next_point.second = nc;
                    }
                } else {
                    q.push(make_pair(nr, nc));
                    visit[nr][nc] = 1;
                }
            }
        }
        if (next_point.first != -1) {
            eat_num++;
            if (eat_num == size) {
                eat_num = 0;
                size++;
            }
            max_time = time;
            while (!q.empty()) q.pop();
            nr = next_point.first;
            nc = next_point.second;
            ocean[nr][nc] = 0;
            q.push(make_pair(nr, nc));
            visit[nr][nc] = 1;
            resetVisit();
        }
    }
    return max_time;
}

int main() {
    set_input();
    int ans = bfs();
    cout << ans << endl;
}