#include <iostream>
#include <vector>

using namespace std;


int N, W, L;

int main() {
    cin >> N >> W >> L;
    
    vector<int> weights(N+1, 0);
    for (int i=0; i<N; i++) {
        cin >> weights[i+1];
        weights[i+1] += weights[i];
    }

    int left = 0, right = 0;
    int time = 0;
    vector<int> truck_time(N+1, 0);
    while (left < N) {
        time++;

        // check left
        if (time - truck_time[left+1] == W)
            left++;
        
        // check right
        if (right + 1 >= weights.size())
            continue;
        if (weights[right+1] - weights[left] <= L)
            truck_time[++right] = time;
    }
    cout << time;
}

/*
size: N + 1
0  1  2  3  4 (idx)
----------------------------------
0  7  4  5  6 (truck weight)
0  7 11 16 22 (accumulate)


1) left 체크: if time - time_vector[left+1] == W: left++
2) right 체크: if acc[right+1] - acc[left] <= L: time_vector[++right] = time


time: 1
time vector: [0 1]
left: 0, right: 1
7 - 0 = 7

time: 2
time vector: [0 1]
left: 0, right: 1
7 - 0 = 7

time: 3
time vector: [0 1 3]
left: 1, right: 1 (left++)
left: 1, right: 2 (right++)
11 - 7 = 4

time: 4
time vector: [0 1 3 4]
left: 1, right: 3 (right++)
16 - 7 = 9

time: 5
time vector: [0 1 3 4]
left: 2, right: 3 (left++)
16 - 11 = 5

time: 6
time vector: [0 1 3 4 6]
left: 3, right: 3 (left++)
left: 3, right: 4 (right++)
22 - 16 = 6

time: 7
time vector: [0 1 3 4 6]
left: 3, right: 4
22 - 16 = 6

time: 8
time vector: [0 1 3 4 6]
left: 4, right: 4 (left++)
22 - 22 = 0

*/