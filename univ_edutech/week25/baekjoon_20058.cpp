#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;


int N;
int Q;
vector<vector<int>> board(64, vector<int>(64));

void print_board(vector<vector<int>> tmp) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << tmp[i][j] << " ";
        } cout << endl;
    } cout << endl;
    cout << endl;
}

void lotate(int y, int x, int size, vector<vector<int>>& tmp) {
    int n_size = size;

    for (int i=0; i<size/2; i++) { // 로테이트 해야 하는 바깥 범위
        // 왼쪽 위부터 시작
        int board_y = y + i;
        int board_x = x + i;

        // 오른쪽 위부터 시작
        int tmp_y = y + i;
        int tmp_x = x + i + n_size - 1;

        // 위 -> 오
        for (int k=0; k<n_size-1; k++, board_x++, tmp_y++)
            tmp[tmp_y][tmp_x] = board[board_y][board_x];

        // 오 -> 밑
        for (int k=0; k<n_size-1; k++, board_y++, tmp_x--)
            tmp[tmp_y][tmp_x] = board[board_y][board_x];

        // 밑 -> 왼
        for (int k=0; k<n_size-1; k++, board_x--, tmp_y--)
            tmp[tmp_y][tmp_x] = board[board_y][board_x];

        // 왼 -> 위
        for (int k=0; k<n_size-1; k++, board_y--, tmp_x++)
            tmp[tmp_y][tmp_x] = board[board_y][board_x];

        n_size -= 2;
    }
}

void lotate_all(int size) {
    auto tmp = board;
    for (int y=0; y<N; y+=size) {
        for (int x=0; x<N; x+=size) {
            lotate(y, x, size, tmp);
        }
    }
    board = tmp;
}

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void melt_ice() {
    auto tmp = board;
    int ny, nx;
    for (int y=0; y<N; y++) {
        for (int x=0; x<N; x++) {
            if (board[y][x] == 0)
                continue;

            int ice_num = 0;
            for (int k=0; k<4; k++) {
                ny = y + dy[k];
                nx = x + dx[k];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 0)
                    continue;
                ice_num++;
            }
            if (ice_num < 3)
                tmp[y][x]--;
        }
    }
    board = tmp;
}

int get_total_ice() {
    int ice_num = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            ice_num += board[i][j];
        }
    }
    return ice_num;
}

int bfs(int i, int j, vector<vector<bool>>& visit) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = true;
    int total_block = 1;

    int y, x, ny, nx;
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int k=0; k<4; k++) {
            ny = y + dy[k];
            nx = x + dx[k];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 0 || visit[ny][nx])
                continue;
            q.push({ny, nx});
            visit[ny][nx] = true;
            total_block++;
        }
    }
    return total_block;
}

int get_big_block() {
    int big_block = 0;
    vector<vector<bool>> visit(N, vector<bool>(N, false));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] == 0 || visit[i][j])
                continue;
            int block = bfs(i, j, visit);
            big_block = max(big_block, block);
        }
    }
    return big_block;
}

int main() {
    cin >> N;
    cin >> Q;

    N = pow(2, N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    int l;
    for (int i=0; i<Q; i++) {
        cin >> l;
        lotate_all(pow(2, l));
        melt_ice();
    }

    int total_ice = get_total_ice();
    int big_block = get_big_block();
    cout << total_ice << endl;
    cout << big_block << endl;
}