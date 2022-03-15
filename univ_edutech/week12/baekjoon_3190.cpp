#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;


struct Position{
    Position(int y, int x)
    : y(y), x(x) {}

    int y, x;
};


int N, K, L;
bool board_apple[100][100] = {false, };
bool board_snake[100][100] = {false, };
unordered_map<int, char> time_dir;

int move_snake();
int change_dir(int, char);
pair<int, int> next_position(int, int, int);
bool check_position(int, int);


int main() {
    cin >> N >> K;

    // apple info
    int y, x;
    for (int i=0; i<K; i++) {
        cin >> y >> x;
        board_apple[y-1][x-1] = true;
    }

    // direction info
    cin >> L;
    int t;
    char d;
    for (int i=0; i<L; i++) {
        cin >> t >> d;
        time_dir[t] = d;
    }

    // get answer
    int time = move_snake();
    cout << time;
}

int move_snake() {
    // init snake
    board_snake[0][0] = true;
    int dir = 1; // 0:up, 1:right, 2:down, 3:left

    // start
    deque<Position> dq;
    dq.push_front(Position(0, 0));
    int y = 0, x = 0, t = 0;
    while (!dq.empty()) {
        t++;

        // move snake
        auto yx = next_position(y, x, dir);
        y = yx.first;
        x = yx.second;
        if (!check_position(y, x))
            break;
        
        // check apple
        if (board_apple[y][x])
            board_apple[y][x] = false;
        else {
            auto p = dq.back();
            dq.pop_back();
            
            board_snake[p.y][p.x] = false;
        }
        dq.push_front(Position(y, x));
        board_snake[y][x] = true;

        // check next direction
        auto it = time_dir.find(t);
        if (it != time_dir.end())
            dir = change_dir(dir, it->second);
    }
    return t;
}

int change_dir(int dir, char left_or_right) {
    if (left_or_right == 'L')
        return (dir + 3) % 4;
    else
        return (dir + 1) % 4;
}

pair<int, int> next_position(int y, int x, int dir) {
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    return {y+dy[dir], x+dx[dir]};
}

bool check_position(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= N)
        return false;
    if (board_snake[y][x])
        return false;
    return true;
}