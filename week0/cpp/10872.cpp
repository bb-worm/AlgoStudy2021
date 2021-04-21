#include <iostream>

using namespace std;

int get_factorial(int);

int main() {
    int N;
    cin >> N;
    int factorial = get_factorial(N);
    cout << factorial << endl;
}

int get_factorial(int num) {
    if (num == 0 || num == 1)
        return 1;
    else
        return num * get_factorial(num-1);
}