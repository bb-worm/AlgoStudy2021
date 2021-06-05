#include <iostream>
#include <vector>

using namespace std;

int N, M;
int r, c;
int dir;
vector<vector<int> > board;

void set_input();
int clean_all();
void print_board();


int main() {
    ios_base::sync_with_stdio(0);
    set_input();
    int total_clean = clean_all();
    cout << total_clean << endl;
}

void set_input() {
    cin >> N >> M;
    cin >> r >> c >> dir;
    board.reserve(N);
    for (int i=0; i<N; i++) {
        board[i].reserve(M);
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }
}

int clean_all() {
    vector<vector<int> > visit(N, vector<int>(M, 0));
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    visit[r][c] = 1;
    int total_clean = 1;

    int nr, nc;
    while (true) {
        bool can_clean = false;
        // check space
        for (int i=0; i<4; i++) {
            dir = (dir + 3) % 4;
            nr = r + dr[dir];
            nc = c + dc[dir];
            if (board[nr][nc] != 1 && visit[nr][nc] == 0) {
                can_clean = true;
                visit[nr][nc] = 1;
                total_clean++;
                r = nr;
                c = nc;
                break;
            }
        }
        // no space to clean
        if (!can_clean) {
            r += dr[(dir + 2) % 4];
            c += dc[(dir + 2) % 4];
            if (board[r][c] == 1)
                break;
        }
    }
    return total_clean;
}

void print_board() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << board[i][j] << " ";
        } cout << endl;
    } cout << endl;
}