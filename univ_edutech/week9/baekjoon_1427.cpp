#include <iostream>
#include <string>
#include <queue>

using namespace std;


// string heapSort()로 해놓고 반환 안하니까 메모리 초과 남;
void heapSort(string N) {
    priority_queue<char> pq;
    for (int i=0; i<N.size(); i++)
        pq.push(N[i]);
    while (!pq.empty()) {
        cout << pq.top();
        pq.pop();
    }
}

void countingSort(string N) {
    int digit[10] = {0};
    for (int i=0; i<N.size(); i++)
        digit[N[i] - '0']++;
    for (int i=9; i>=0; i--) {
        for (int j=0; j<digit[i]; j++)
            cout << i;
    }
}

int main() {
    string N;
    cin >> N;
    
    // heapSort(N);
    countingSort(N);
}