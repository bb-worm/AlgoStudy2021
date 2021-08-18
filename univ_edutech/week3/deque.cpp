#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(9);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
}