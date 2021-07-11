#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N, H;
int box[101][101][101];
queue<int> q;

void set_input() {
    ios_base::sync_with_stdio(0);
    cin >> M >> N >> H;
    int t;
    for (int h=0; h<H; h++) {
        for (int n=0; n<N; n++) {
            for (int m=0; m<M; m++) {
                cin >> t;
                box[h][n][m] = t;      
                if (t == 1) {
                    q.push(h);
                    q.push(n);
                    q.push(m);
                }
            }
        }
    }
}

int bfs() {
    int dh[6] = {-1, 1, 0, 0, 0, 0};
    int dn[6] = {0, 0, -1, 1, 0, 0};
    int dm[6] = {0, 0, 0, 0, -1, 1};

    int h, n, m;
    int nh, nn, nm;
    int days = -1;
    while (!q.empty()) {
        int size = q.size()/3;
        days++;
        for (int s=0; s<size; s++) {
            h = q.front();
            q.pop();
            n = q.front();
            q.pop();
            m = q.front();
            q.pop();

            for (int i=0; i<6; i++) {
                nh = dh[i] + h;
                nn = dn[i] + n;
                nm = dm[i] + m;
                if (nh<0 || nn<0 || nm<0 || nh>=H || nn>=N || nm>=M)
                    continue;
                if (box[nh][nn][nm] != 0)
                    continue;
                q.push(nh);
                q.push(nn);
                q.push(nm);
                box[nh][nn][nm] = 1;
            }
        }
    }
    return days;
}

bool is_all_raped() {
    for (int h=0; h<H; h++) {
        for (int n=0; n<N; n++) {
            for (int m=0; m<M; m++) {
                if (box[h][n][m] == 0)
                    return false;
            }
        }
    }
    return true;
}

int main() {
    set_input();
    int days = bfs();
    if (is_all_raped())
        cout << days;
    else
        cout << -1;
}