#include <stdio.h>
#include <queue>

using namespace std;

int BFS(int limit, int start, int goal, int dx[]) {
    int visit[1000001] = {0, };
    queue<int> q;
    q.push(start);
    visit[start] = 1;

    while (!q.empty()) {
        int now = q.front();
        int stage = visit[now];
        q.pop();

        if (now == goal)
            return stage - 1; // Because start point is 1

        int next;
        for (int i=0; i<2; i++) {
            next = now + dx[i];
            if (next > limit || next <= 0)
                continue;
            if (visit[next] != 0)
                continue;
            q.push(next);
            visit[next] = stage + 1;
        }
    }

    return -1;
}

int main() {
    int F, S, G, U, D;
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    int dx[2] = {U, D*-1};

    int ans = BFS(F, S, G, dx);
    if (ans == -1)
        printf("use the stairs");
    else
        printf("%d\n", ans);
}