#include <iostream>
#include <vector>

using namespace std;


int ans = -1;

// start point
int sdy[4] = {0, 0, 1, 1};
int sdx[4] = {1, 1, 0, 0};

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void print_board(vector<vector<int>> board) {
    int N = board.size();
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << board[i][j] << " ";
        } cout << endl;
    } cout << endl;
    
}

vector<vector<int>> move_board(int dir, vector<vector<int>> board) {
    // if (dir == 0) cout << "up" << endl;
    // else if (dir == 1) cout << "down" << endl;
    // else if (dir == 2) cout << "left" << endl;
    // else cout << "right" << endl;
    // print_board(board);

    int N = board.size();

    // set start_point
    int sy, sx;
    if (dir == 0) { // up 
        sy = 0, sx = 0;
    } else if (dir == 1) { // down
        sy = N - 1, sx = 0;
    } else if (dir == 2) { // left
        sy = 0, sx = 0;
    } else { // right
        sy = 0, sx = N - 1;
    }

    // combine & compact
    int y, x, tmp_y, tmp_x;
    for (int i=0; i<N; i++) {
        // combine
        int pre_num = -1;
        y = sy, x = sx;
        for (int j=0; j<N; j++) {
            if (board[y][x] == pre_num) {
                board[y][x] = 0;
                board[tmp_y][tmp_x] *= 2;
                pre_num = -1;
            } else if (board[y][x] != 0) {
                pre_num = board[y][x];
                tmp_y = y;
                tmp_x = x;
            }
            y += dy[dir];
            x += dx[dir];
        }
        // compact
        y = sy, x = sx;
        tmp_y = sy, tmp_x = sx;
        for (int j=0; j<N; j++) {
            if (board[y][x] != 0) {
                if (y != tmp_y || x != tmp_x) { // 처음에 && 연산으로 해서 틀림
                    board[tmp_y][tmp_x] = board[y][x];
                    board[y][x] = 0;
                }
                tmp_y += dy[dir];
                tmp_x += dx[dir];
            }
            y += dy[dir];
            x += dx[dir];
            
        }
        sy += sdy[dir];
        sx += sdx[dir];
    }
    
    // print_board(board);
    return board;
}

int cal_max_num(const vector<vector<int>>& board) {
    int max_num = -1;
    for (auto& row : board) {
        for (auto val : row) {
            max_num = max(max_num, val);
        }
    }
    return max_num;
}

void dfs(int times, const vector<vector<int>>& board) {
    if (times >= 5) {
        ans = max(ans, cal_max_num(board));
        return;
    }

    for (int i=0; i<4; i++) {
        auto new_board = move_board(i, board);
        dfs(times + 1, new_board);
    }
}

int main() {
    // set input
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    // dfs
    dfs(0, board);
    cout << ans << endl;
}