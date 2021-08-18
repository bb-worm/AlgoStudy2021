#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    for (int i=0; i<10; i++) {
        q.push(i);
    }
    for (int i=0; i<10; i++) {
        cout << q.front() << endl;
        q.pop();
    }
}