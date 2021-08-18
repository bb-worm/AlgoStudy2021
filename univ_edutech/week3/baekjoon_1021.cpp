#include <stdio.h>
#include <deque>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    deque<int> dq;
    
    for (int i=1; i<=N; i++)
        dq.push_back(i);

    int sum = 0;
    for (int i=0; i<M; i++) {
        int goal, cnt = 0;
        scanf("%d", &goal);
        
        int tmp;
        while (dq.front() != goal) {
            cnt++;
            tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
        }
        
        if (cnt > dq.size() - cnt)
            cnt = dq.size() - cnt;
        sum += cnt;
        dq.pop_front();
    }
    printf("%d\n", sum);
}

/*
1 2 3 4 5 6 7 8 9 10
2 3 4 5 6 7 8 9 10 1 - pop
3 4 5 6 7 8 9 10 1
1 3 4 5 6 7 8 9 10
10 1 3 4 5 6 7 8 9
9 10 1 3 4 5 6 7 8 - pop
10 1 3 4 5 6 7 8
8 10 1 3 4 5 6 7
7 8 10 1 3 4 5 6
6 7 8 10 1 3 4 5
5 6 7 8 10 1 3 4 - pop
*/