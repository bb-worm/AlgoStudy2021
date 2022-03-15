#include <iostream> // cin 썼더니 엄청 느림 
#include <stdio.h> // 500ms -> 160ms
#include <vector>

using namespace std;


int main() {
    // set input
    int N;
    scanf("%d", &N);
    vector<int> rooms(N);
    for (int i=0; i<N; i++)
        scanf("%d", &rooms[i]);
    
    int B, C;
    scanf("%d %d", &B, &C);

    long long ans = 0; // 처음에 int로 선언해서 틀림
    for (int i=0; i<N; i++) {
        // 총감독관
        rooms[i] -= B;
        ans++;

        // 부감독관
        if (rooms[i] <= 0)
            continue;
        ans += rooms[i] / C;
        if (rooms[i] % C != 0)
            ans++;
    }
    printf("%lld\n", ans);
}