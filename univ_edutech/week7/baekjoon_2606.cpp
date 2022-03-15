#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Com {
    Com(int num) : num(num) {}
    int num;
    bool visit = false;
    vector<Com*> next;
};

void BFS(vector<Com*> coms) {
    queue<Com*> q;
    q.push(coms[0]);
    coms[0]->visit = true;

    while (!q.empty()) {
        Com* now = q.front();
        q.pop();

        for (auto& n : now->next) {
            if (n->visit)
                continue;
            n->visit = true;
            q.push(n);
        }
    }
}

void DFS(Com* com) {
    com->visit = true;

    for (auto& n : com->next) {
        if (n->visit)
            continue;
        n->visit = true;
        DFS(n);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // make computers
    vector<Com*> coms;
    for (int i=0; i<V; i++)
        coms.push_back(new Com(i+1));

    // connect computers
    int a, b;
    for (int i=0; i<E; i++) {
        scanf("%d %d", &a, &b);
        coms[a-1]->next.push_back(coms[b-1]);
        coms[b-1]->next.push_back(coms[a-1]);
    }

    // BFS(coms);
    DFS(coms[0]);

    // check visit
    int cnt = -1;
    for (auto& com : coms) {
        if (com->visit)
            cnt++;
    }
    
    printf("%d\n", cnt);
}