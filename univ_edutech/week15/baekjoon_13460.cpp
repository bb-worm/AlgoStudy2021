#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;
/*

board (N * M)

. 빈 칸
# 벽
O 구멍
R 빨간 구슬
B 파란 구슬

최대 10번 움직임
기울이는 방향 4가지
=> 4^10 => 백만가지

최소 횟수 구하는 거라 BFS?
못 빼낼 수도 있다고 하니 DFS도 가능

*/

int N, M;
int ans;

void dfs(int, const vector<vector<char>>&, const pair<int, int>&, const pair<int, int>&, int);
void print_board(vector<vector<char>>);

int main() {
    cin >> N >> M;

    pair<int, int> red;
    pair<int, int> blue;
    vector<vector<char>> board(N, vector<char>(M));
    for (int i=0; i<N; i++) {
        string line;
        cin >> line;
        for(int j=0; j<M; j++) {
            board[i][j] = line[j];
            if (line[j] == 'R')
                red = {i, j};
            else if (line[j] == 'B')
                blue = {i, j};
        }
    }

    ans = INT_MAX;
    dfs(1, board, red, blue, -1);

    // no answer
    if (ans == INT_MAX)
        ans = -1;
    cout << ans << endl;
}

bool red_first(int dir, const pair<int, int>& red, const pair<int, int>& blue) {
    if (dir == 0) { // up
        if (red.first <= blue.first)
            return true;
        else return false;
    } else if (dir == 1) { // down
        if (red.first >= blue.first)
            return true;
        else return false;
    } else if (dir == 2) { // left
        if (red.second <= blue.second)
            return true;
        else return false;
    } else { // right
        if (red.second >= blue.second)
            return true;
        else return false;
    }
}

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool move_ball(int dir, vector<vector<char>>& board, pair<int, int>& ball) {
    int y = ball.first;
    int x = ball.second;
    auto ball_char = board[y][x];
    board[y][x] = '.';
    
    // next position
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    while (board[ny][nx] == '.') {
        ny += dy[dir];
        nx += dx[dir];
    }

    // cout << y << " " << x << endl;
    // cout << board[y][x] << endl;
    // print_board(board);
    if (board[ny][nx] == '#' || board[ny][nx] == 'R' || board[ny][nx] == 'B') {
        y = ny - dy[dir];
        x = nx - dx[dir];
        ball.first = y;
        ball.second = x;
        board[y][x] = ball_char;
        return false;
    } else // 'O'
        return true;
}

// char: 1 byte
// vector<vector<char>> board: 최대 10*10 byte
// dfs 최대 깊이: 10
// dfs 한 depth에서 만들어지는 board: 4개 (사실 3개)
// 10*10*10*4 byte => 4000 byte => 4 kb
void dfs(int stage, const vector<vector<char>>& board, const pair<int, int>& red, const pair<int, int>& blue, int pre_dir) {
    if (stage >= ans || stage > 10)
        return;

    // 0:up, 1:down, 2:left, 3:right
    for (int i=0; i<4; i++) {
        if (pre_dir == i)
            continue;

        auto next_board = board;
        auto next_red = red;
        auto next_blue = blue;

        bool red_gone = false;
        bool blue_gone = false;

        if (red_first(i, red, blue)) {
            red_gone = move_ball(i, next_board, next_red);
            blue_gone = move_ball(i, next_board, next_blue);
        } else {
            blue_gone = move_ball(i, next_board, next_blue);
            red_gone = move_ball(i, next_board, next_red);
        }

        if (red_gone && !blue_gone) { // success & return
            ans = stage;
            return;
        } else if (!red_gone && !blue_gone) { // next stage
            dfs(stage+1, next_board, next_red, next_blue, i);
        }
    }
}

void print_board(vector<vector<char>> board) {
    for(int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << board[i][j];
        } cout << endl;
    } cout << endl;
}