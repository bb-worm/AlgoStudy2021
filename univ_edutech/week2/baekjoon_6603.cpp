#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

void print_lotto(int idx, int total_choose, vector<int>& nums, string result) {
    if (total_choose == 6) {
        printf("%s\n", result.c_str());
        return;
    }

    if (idx >= nums.size())
        return;

    print_lotto(idx+1, total_choose+1, nums, result + to_string(nums[idx]) + " ");
    print_lotto(idx+1, total_choose, nums, result);
}

void print_lotto2(int idx, int total_choose, vector<int>& nums, vector<int>& result) {
    if (total_choose == 6) {
        for (int i=0; i<6; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }

    if (idx >= nums.size())
        return;

    result[total_choose] = nums[idx];
    print_lotto2(idx+1, total_choose+1, nums, result);
    print_lotto2(idx+1, total_choose, nums, result);
}

int main() {
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;

        vector<int> nums;
        int num;
        for (int i=0; i<n; i++) {
            scanf("%d", &num);
            nums.push_back(num);
        }
        // print_lotto(0, 0, nums, "");
        vector<int> result(6, 0);
        print_lotto2(0, 0, nums, result);
        printf("\n");
    }
}