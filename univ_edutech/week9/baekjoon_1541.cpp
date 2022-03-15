#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 음수 발견하면 그 뒤로 다 빼면 됨
// 첫 번째 음수 전까진 다 더함
int main() {
    string input;
    cin >> input;

    // parsing
    vector<int> nums;
    int pre = 0;
    int first_minus = -1;
    for (int i=0; i<input.length(); i++) {
        if (input[i] == '+') {
            nums.push_back(pre);
            pre = 0;
        } else if (input[i] == '-') {
            nums.push_back(pre);
            pre = 0;
            if (first_minus == -1)
                first_minus = nums.size();
        } else { // number
            pre = pre*10 + (input[i] - '0');
        }
    }
    nums.push_back(pre);

    // no minus
    if (first_minus == -1)
        first_minus = nums.size();

    // calculate
    int ans = 0;

    for (int i=0; i<first_minus; i++)
        ans += nums[i];
    for (int i=first_minus; i<nums.size(); i++)
        ans -= nums[i];

    cout << ans;
}