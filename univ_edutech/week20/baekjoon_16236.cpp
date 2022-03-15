#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Shark {
    int y, x;
    int size = 2;
    int eat_fish_num = 0;
};

struct Target {
    int y, x;
    int distance;
    bool is_valid;
};

int N;
int ans = 0;
vector<vector<int>> board(20, vector<int>(20));

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void print_board(Shark shark) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i == shark.y && j == shark.x)
                cout << '*' << " ";
            else
                cout << board[i][j] << " ";
        } cout << endl;
    } cout << endl;
    cout << endl;
}

Target get_fish_location(Shark shark) {
    vector<vector<bool>> visit(N, vector<bool>(N, false));
    queue<pair<int, int>> q;
    q.push({shark.y, shark.x});
    visit[shark.y][shark.x] = true;

    vector<pair<int, int>> can_eat;
    int distance = 0;
    while (!q.empty()) {
        distance++;

        int size = q.size();
        for (int i=0; i<size; i++) {
            auto& now = q.front();
            q.pop();

            int ny, nx;
            for (int j=0; j<4; j++) {
                ny = now.first + dy[j];
                nx = now.second + dx[j];

                if (ny<0 || ny>=N || nx<0 || nx>=N || visit[ny][nx] || board[ny][nx] > shark.size)
                    continue;

                if (board[ny][nx] != 0 && board[ny][nx] < shark.size) {
                    can_eat.push_back({ny, nx});
                    visit[ny][nx] = true;
                    continue;
                }

                q.push({ny, nx});
                visit[ny][nx] = true;
            }
        }

        if (can_eat.size() == 0)
            continue;
        
        Target ret = {20, 20, distance, true};
        for (auto& p : can_eat) {
            if (p.first < ret.y) {
                ret.y = p.first;
                ret.x = p.second;
            } else if (p.first == ret.y && p.second < ret.x) {
                ret.x = p.second;
            }
        }
        return ret;
    }

    return Target{-1, -1, 0, false};

}

// 1. distance 잘못 계산함
// 2. 물고기 다 먹은 경우 생각 안 함
// 3. BFS에서 범위 검증할 때 ny 두번 체크함..
void DFS(Shark shark, int time, int total_fish, int fish_eaten_num) {
    // no fish
    if (total_fish == fish_eaten_num) {
        ans = time;
        return;
    }

    // check fish
    auto target = get_fish_location(shark);
    if (!target.is_valid) {
        ans = time;
        return;
    }

    // eat fish
    board[target.y][target.x] = 0;

    Shark next_shark;
    if (shark.size == shark.eat_fish_num + 1)
        next_shark = Shark{target.y, target.x, shark.size + 1, 0};
    else
        next_shark = Shark{target.y, target.x, shark.size, shark.eat_fish_num + 1};

    // cout << "size: " << next_shark.size << endl;
    // cout << "eat fish: " << next_shark.eat_fish_num << endl;
    
    // cout << "time: " << time + target.distance << endl;
    // print_board(next_shark);

    // next DFS
    DFS(next_shark, time + target.distance, total_fish, fish_eaten_num + 1);
}

int main() {
    cin >> N;

    Shark shark;
    
    int total_fish = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark = Shark{i, j};
                board[i][j] = 0;
            } else if (board[i][j] != 0)
                total_fish++;
        }
    }

    DFS(shark, 0, total_fish, 0);
    cout << ans << endl;
}