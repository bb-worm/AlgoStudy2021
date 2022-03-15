#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;


int main() {
    int N;
    scanf("%d", &N);

    vector<int> nums(N);
    int n;
    for (int i=0; i<N; i++) {
        scanf("%d", &n);
        nums[i] = n;
    }

    sort(nums.begin(), nums.end());

    pair<int, int> ans;
    int ans_sum = INT_MAX;

    int start = 0, end = N-1;
    while (start < end && ans_sum != 0) {
        int sum = abs(nums[start] + nums[end]);
        if (sum < ans_sum) {
            ans_sum = sum;
            ans.first = nums[start];
            ans.second = nums[end];
        }

        if (abs(nums[start]) < abs(nums[end]))
            end--;
        else
            start++;
    }

    printf("%d %d\n", ans.first, ans.second);
}