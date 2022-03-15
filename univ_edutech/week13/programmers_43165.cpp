#include <string>
#include <vector>
#include <iostream>

using namespace std;


int dfs(int idx, vector<int> numbers, int result, int target) {
    if (idx >= numbers.size())
        return result == target ? 1 : 0;

    return dfs(idx+1, numbers, result+numbers[idx], target) 
         + dfs(idx+1, numbers, result-numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    return dfs(0, numbers, 0, target);
}


int main() {
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;

    int ans = solution(numbers, target);
    cout << ans;
}