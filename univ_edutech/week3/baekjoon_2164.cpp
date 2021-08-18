#include <stdio.h>
#include <queue>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    queue<int> q;
    for (int i=1; i<=N; i++)
        q.push(i);
    
    int tmp;
    while (q.size() != 1) {
        q.pop();
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    printf("%d\n", q.front());
}