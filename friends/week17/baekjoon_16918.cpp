#include <iostream>
#include <vector>
#include <string>

using namespace std;


void fill_board(vector<vector<char>>& board) {
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            if (board[i][j] == '.')
                board[i][j] = 'O';
        }
    }
}

void bomb_board(vector<vector<char>>& board, vector<vector<bool>>& bomb) {
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            if (bomb[i][j]) {
                board[i][j] = '.';
                int y, x;
                for (int k=0; k<4; k++) {
                    y = i + dy[k];
                    x = j + dx[k];
                    if (y<0 || x<0 || y>=board.size() || x>=board[0].size())
                        continue;
                    board[y][x] = '.';
                }
            }
        }
    }

    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            if (board[i][j] == '.')
                bomb[i][j] = false;
            else
                bomb[i][j] = true;
        }
    }
}

void print_board(vector<vector<char>> board) {
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[i].size(); j++) {
            printf("%c", board[i][j]);
        }printf("\n");
    }printf("\n");
}

int main() {
    int R, C, N;
    cin >> R >> C >> N;

    vector<vector<char>> board;
    vector<vector<bool>> bomb;

    for (int i=0; i<R; i++) {
        vector<char> tmp;
        vector<bool> tmp2;
        string row;
        cin >> row;
        for (int j=0; j<C; j++) {
            tmp.push_back(row[j]);
            if (row[j] == 'O')
                tmp2.push_back(true);
            else
                tmp2.push_back(false);
        }
        board.push_back(tmp);
        bomb.push_back(tmp2);
    }

    int time = 1;
    while (time < N) {

        if (time % 2 != 0) {
            fill_board(board);
        } else {
            bomb_board(board, bomb);
        }
        time++;
    }
    print_board(board);
}