#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int ans = 0;

struct Fish {
    int x, y;
    int num;
    int dir; // 0~7
    bool eaten;
};

void print_fishes(vector<vector<Fish>> fishes) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (!fishes[i][j].eaten)
                printf("%2d ", fishes[i][j].num);
            else
                printf("00 ");
        } 
        cout << "     ";
        for (int j=0; j<4; j++) {
            printf("%2d ", fishes[i][j].dir);
        } cout << endl;
    } cout << endl;
    cout << endl;
}

// 위부터 반시계
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void move_fishes(vector<vector<Fish>>& fishes, int shark_x, int shark_y) {
    // cout << "before" << endl;
    // print_fishes(fishes);

    vector<Fish> fish_order(17);
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            fish_order[fishes[i][j].num] = fishes[i][j];
        }
    }

    for (int i=1; i<=16; i++) {
        if (fish_order[i].eaten)
            continue;

        auto& now = fish_order[i];
        int x = now.x, y = now.y;

        for (int j=0; j<8; j++) {
            int nx = x + dx[now.dir];
            int ny = y + dy[now.dir];
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || (nx == shark_x && ny == shark_y)) {
                now.dir = (now.dir + 1) % 8;
                continue;
            }
                
            auto& next = fish_order[fishes[nx][ny].num];

            // swap fishes
            next.x = x;
            next.y = y;
            fishes[x][y] = next;

            now.x = nx;
            now.y = ny;
            fishes[nx][ny] = now;

            break;
        }
    }
    // cout << "after" << endl;
    // print_fishes(fishes);
}

void DFS(int x, int y, vector<vector<Fish>> fishes, int total_fish) {
    // eat fish (shark)
    int dir = fishes[x][y].dir;
    int n_total_fish = total_fish + fishes[x][y].num;
    fishes[x][y].eaten = true;

    // move (fishes)
    move_fishes(fishes, x, y);

    // go next position (shark)
    int nx = x, ny = y;
    while (true) {
        nx += dx[dir];
        ny += dy[dir];

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) { // 범위 벗어나면 break
            ans = max(ans, n_total_fish);
            break;
        } else if (fishes[nx][ny].eaten) { // 잡아먹힌 곳이면 continue
            ans = max(ans, n_total_fish);
            continue;
        }
        DFS(nx, ny, fishes, n_total_fish);
        // break;
    }
}

int main() {
    vector<vector<Fish>> fishes(4, vector<Fish>(4));
    int num, dir;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cin >> num >> dir;
            fishes[i][j] = Fish{i, j, num, dir-1, false};
        }
    }

    DFS(0, 0, fishes, 0);
    cout << ans << endl;
}