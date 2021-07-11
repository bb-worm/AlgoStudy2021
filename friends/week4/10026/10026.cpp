#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;
vector<string> pic;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void set_input();
int get_area(bool);
void bfs(int, int, vector<vector<int> >&, bool);

int main() {
    ios_base::sync_with_stdio(0);
    set_input();
    int area1 = get_area(false);
    int area2 = get_area(true);
    cout << area1 << " " << area2 << endl;
}

void set_input() {
    cin >> N;
    string input;
    for (int i=0; i<N; i++) {
        cin >> input;
        pic.push_back(input);
    }
}

int get_area(bool include_red_green) {
    int total_area = 0;
    vector<vector<int> > visit(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (visit[i][j] == 0) {
                bfs(i, j, visit, include_red_green);
                total_area++;
            }
        }
    }
    return total_area;
}

void bfs(int i, int j, vector<vector<int> > &visit, bool include_red_green) {
    char base_color = pic[i][j];

    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    visit[i][j] = 1;

    int r, c;
    int nr, nc;
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            nr = r + dr[k];
            nc = c + dc[k];
            if (nr<0 || nc<0 || nr>=N || nc>=N || visit[nr][nc]==1)
                continue;
            char next_color = pic[nr][nc];
            if (base_color == next_color) {
                q.push(make_pair(nr, nc));
                visit[nr][nc] = 1;
            } else if (include_red_green) {
                if ((base_color=='R' and next_color=='G') || (base_color=='G' and next_color=='R')) {
                    q.push(make_pair(nr, nc));
                    visit[nr][nc] = 1;
                }
            }
        }
    }
}