#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int i=0; i<T; i++) {
        stack<char> s;
        string str;
        cin >> str;
        
        for (auto& ch : str) {
            if (ch == '(') {
                s.push('(');
            } else if (ch == ')') {
                if (s.empty()){
                    s.push('(');
                    break;
                }
                else
                    s.pop();
            }
        }
        if (s.empty())
            printf("YES\n");
        else
            printf("NO\n");
    }
}