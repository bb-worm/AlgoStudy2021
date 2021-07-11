// https://programmers.co.kr/learn/courses/30/lessons/1836

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;

/*
A-Z 순서로 bfs를 진행하다가 중간에 bfs 성공하는 알파벳 있으면 처음부터 다시 bfs 진행해야 함.

1) 알파벳 순회
알파벳 개수를 M이라고 하면, 최악의 경우엔 항상 끝에 있는 알파벳이 bfs를 성공하게 됨
=> M + (M-1) + (M-2) + ... + 1
= (M*(M+1)) / 2

2) BFS
BFS는 위치정보에 방향과 꺾은 여부에 따라 방문을 체크함.
방향은 4방향, 꺾은 여부는 2가지이므로 board가 N*N일 때 시간복잡도는
=> N*N*4*2

위 두가지 경우를 고려했을 때 시간복잡도는 O((M*(M+1)/2 * N*N*8*2)로 볼 수 있음.
M은 최대 26, N은 최대 100이므로, 대강 O(3천만)으로 계산해볼 수 있음.
*/

bool bfs(char, vector<vector<char>>&, pair<int, int>);

string solution(int m, int n, vector<string> board) {
    // board 관리하기 편하게 2차원 벡터로 옮겨줬음
    vector<vector<char>> new_board;
    for (int i=0; i<m; i++) {
        vector<char> tmp;
        for (int j=0; j<n; j++) {
            tmp.push_back(board[i][j]);
        }
        new_board.push_back(tmp);
    }

    // 알파벳 위치 정보 저장해줬음. 시작 위치만 정하면 되니까 두개 중 하나면 저장함.
    unordered_map<char, pair<int, int>> char_location;
    set<char> alpha;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            char ch = board[i][j];
            if (ch != '*' && ch != '.') {
                alpha.insert(ch);
                char_location[ch] = make_pair(i, j);
            }
        }
    }

    // 본격적으로 bfs 시작.
    // 알파벳 순서대로 bfs 하면서
    // 1) 없앨 수 있는 알파벳이면 없애고 다시 처음부터 알파벳 순서로 bfs
    // 2) 없앨 수 없는 알파벳이면 다음 알파벳 bfs
    // set에 저장하면 기본적으로 ordered_set 되므로 사용했음.
    string ans = "";
    bool find = true;
    while (find) {
        find = false;
        for (auto& ch : alpha) {
            pair<int, int> loca = char_location[ch];
            if (bfs(ch, new_board, loca)) {
                find = true;
                ans += ch;
                alpha.erase(ch);
                break;
            }
        }
    }

    // 만약 아직 없애지 못한 알파벳이 남아있으면 impossible
    if (alpha.size() != 0)
        ans = "IMPOSSIBLE";
    return ans;
}

// bfs에서 스텝 저장할 구조체 만들었음.
struct step {
    pair<int, int> loca;
    // up right down left
    // 0  1    2    3
    int dir;
    int curve;
};

int ddir[3] = {0, 3, 1};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool bfs(char ch, vector<vector<char>>& board, pair<int, int> loca) {
    int m = board.size();
    int n = board[0].size();

    // visit이 중요한데,
    // 특정 위치뿐 아니라 해당 위치를 방문했을 때 방향(dir)과 경로 꺾었는지(curve) 여부도 저장해야함.
    // 체크해야할 사항 늘어난 거 외에는 단순 bfs랑 같음.
    bool visit[101][101][4][2] = {false};
    // visit 만들 때 101 대신 m, n 값 집어넣어서 한 시간 날린 듯. 왜 컴파일 되지???
    // 변수 넣어주니까 cout 쓸 때마다 결과가 달라졌음;

    // 일단 시작 지점을 큐에 넣어줌.
    queue<step> q;
    for (int i=0; i<4; i++) {
        step start = {loca, i, 0};
        q.push(start);
        visit[loca.first][loca.second][i][0] = true;
    }

    // bfs 시작
    step now;
    while (!q.empty()) {
        now = q.front();
        q.pop();

        int ny, nx;
        int ndir, ncurve;
        for (int i=0; i<3; i++) {
            // ndir은 새로운 방향을 의미함
            // 현재 방향 기준으로 갈 수 있는 방향은 세가지인데, (곧장, 왼쪽, 오른쪽)이 있음.
            ndir = (now.dir + ddir[i]) % 4;

            // curve 체크
            if (ndir != now.dir) {
                // 만약 이미 꺾었는데 다시 꺾는 방향이면 continue
                if (now.curve == 1)
                    continue;
                ncurve = now.curve + 1;
            } else {
                ncurve = now.curve;
            }

            // 가려는 방향에 따라 새로운 좌표 만들어줌.
            ny = now.loca.first + dy[ndir];
            nx = now.loca.second + dx[ndir];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n) // 범위 체크
                continue;
            if (visit[ny][nx][ndir][ncurve]) // 방문 체크
                continue;

            // 종료 지점
            // 만약 시작 알파벳이랑 같은 알파벳에 도착했으면
            // .으로 바꿔주고 bfs 끝냄.
            if (board[ny][nx] == ch && (ny != loca.first || nx != loca.second)) {
                board[ny][nx] = '.';
                board[loca.first][loca.second] = '.';
                return true;
            }

            // 이동할 수 있는 곳인지 체크
            if (board[ny][nx] != '.')
                continue;

            // 다음 탐색 정보(다음 위치, 방향, 꺾은 여부)를 담은 구조체 만들어서 큐에 넣어줌.
            step next = {make_pair(ny, nx), ndir, ncurve};
            q.push(next);
            visit[ny][nx][ndir][ncurve] = true;
        }
    }
    return false;
}

int main() {
    int m = 3;
    int n = 3;
    vector<string> board = {"DBA", "C*A", "CDB"};

    string ans = solution(m, n, board);
    cout << ans << endl;
}