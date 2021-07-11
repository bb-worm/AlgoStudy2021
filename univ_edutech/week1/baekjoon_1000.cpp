#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void use_stdio() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
}

void use_iostream() {
    std::ios::sync_with_stdio(false);

    int a, b;
    std::cin >> a >> b;
    std::cout << a+b << std::endl;
}

void use_string_split() {
    std::string input;
    getline(std::cin, input); // "1 2"
    std::istringstream ss(input); // (ss)"1 2"
    std::string stringBuffer;
    int ans = 0;
    int num;
    while (getline(ss, stringBuffer, ' ')) {
        ans += stoi(stringBuffer);
    }
    std::cout << ans << "\n";
}

int main() {
    // use_stdio();
    // use_iostream();
    use_string_split();
}