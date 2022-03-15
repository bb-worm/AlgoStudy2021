#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int MAX_VAL = INT_MIN;
int MIN_VAL = INT_MAX;


int cal_next(int oper, int a, int b) {
    if (oper == 0) {
        return a + b;
    } else if (oper == 1) {
        return a - b;
    } else if (oper == 2) {
        return a * b;
    } else {
        return a / b;
    }
}

void cal(int result, vector<int>& nums, vector<int>& oper_nums, int idx) {
    if (idx >= nums.size()) {
        MAX_VAL = max(MAX_VAL, result);
        MIN_VAL = min(MIN_VAL, result);
        return;
    }
    
    for (int i=0; i<4; i++) {
        if (oper_nums[i] == 0)
            continue;
        oper_nums[i]--;
        int next = cal_next(i, result, nums[idx]);
        cal(next, nums, oper_nums, idx+1);
        oper_nums[i]++;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> nums;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<int> oper_nums;
    for (int i=0; i<4; i++) {
        int num;
        cin >> num;
        oper_nums.push_back(num);
    }

    cal(nums[0], nums, oper_nums, 1);

    cout << MAX_VAL << "\n" << MIN_VAL;
}