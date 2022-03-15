#include <iostream>
#include <vector>

using namespace std;


int N, M;
vector<vector<int>> floor(50, vector<int>(50));

int robot_y, robot_x;
int robot_dir;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int get_new_dir() {
    int n_dir = robot_dir;
    for (int i=0; i<4; i++) {
        n_dir = (n_dir + 3) % 4; // 왼쪽으로 돌림
        if (floor[robot_y + dy[n_dir]][robot_x + dx[n_dir]] == 0) // 청소 가능?
            return n_dir;
    }
    return -1;
}

int get_cleaned_room() {
    int cleaned_room = 0;
    
    int n_dir;
    while (true) {
        if (floor[robot_y][robot_x] == 0) {
            cleaned_room++;
            floor[robot_y][robot_x] = 2; // cleaned: 2
        }

        n_dir = get_new_dir(); // 청소 가능한 방향 찾기
        if (n_dir != -1) { // 해당 방향으로 돌리고 이동
            robot_dir = n_dir;
            robot_y += dy[robot_dir];
            robot_x += dx[robot_dir];
        } else { // 청소 불가능
            int back_dir = (robot_dir + 2) % 4;

            if (floor[robot_y + dy[back_dir]][robot_x + dx[back_dir]] != 1) { // 후진 가능
                robot_y += dy[back_dir];
                robot_x += dx[back_dir];
            } else { // 후진 불가
                break;
            }
        }
    }
    return cleaned_room;
}

int main() {
    cin >> N >> M;
    cin >> robot_y >> robot_x >> robot_dir;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> floor[i][j];
        }
    }

    int cleaned_room = get_cleaned_room();
    cout << cleaned_room << endl;
}