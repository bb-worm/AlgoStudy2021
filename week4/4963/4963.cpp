#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int w, h;
int map[50][50];
queue<pair<int, int> > q;

int find_island_num();
void bfs(int, int, int[][50]);

int main() {
    ios_base::sync_with_stdio(0);
    vector<int> ans;
    while (true) {
        cin >> w >> h;
        if (w+h == 0)
            break;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin >> map[i][j];
            }
        }
        ans.push_back(find_island_num());
    }
    for (int& it : ans)
        cout << it << endl;
}

int find_island_num() {
    int island_num = 0;
    int n_map[50][50];
    memcpy(n_map, map, 50*50*sizeof(int));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (n_map[i][j] == 1) {
                bfs(i, j, n_map);
                island_num++;
            }
        }
    }
    
    return island_num;
}

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void bfs(int i, int j, int n_map[][50]) {
    q.push(make_pair(i, j));
    n_map[i][j] = 0;

    int r, c;
    int nr, nc;
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (int k=0; k<8; k++) {
            nr = r + dr[k];
            nc = c + dc[k];
            if (nr<0 || nc<0 || nr>=h || nc>=w)
                continue;
            if (n_map[nr][nc] != 1)
                continue;

            n_map[nr][nc] = 0;
            q.push(make_pair(nr, nc));
        }
    }

}