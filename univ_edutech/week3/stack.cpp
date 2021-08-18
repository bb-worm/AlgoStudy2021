#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    for (int i=0; i<10; i++) {
        s.push(i);
    }
    // 0 1 2 3 4 5 6 7 8 9
    for (int i=0; i<10; i++) {
        cout << s.top() << endl;
        s.pop();
    }
    s.empty();
}