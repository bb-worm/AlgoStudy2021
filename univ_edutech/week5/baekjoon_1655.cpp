#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
    int N;
    cin >> N;

    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);

        // handle first num
        if (maxHeap.empty()) {
            maxHeap.push(num);
            printf("%d\n", num);
            continue;
        }

        // push num
        if (maxHeap.top() < num)
            minHeap.push(num);
        else
            maxHeap.push(num);

        // for heap balance
        int tmp;
        if (maxHeap.size() > minHeap.size() + 1) {
            tmp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(tmp);
        } else if (maxHeap.size() < minHeap.size()){
            tmp = minHeap.top();
            minHeap.pop();
            maxHeap.push(tmp);
        }

        // print center value
        if (minHeap.size() != maxHeap.size())
            printf("%d\n", maxHeap.top());
        else
            printf("%d\n", min(maxHeap.top(), minHeap.top()));
    }
}