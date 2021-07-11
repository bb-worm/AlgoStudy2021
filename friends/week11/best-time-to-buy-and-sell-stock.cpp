#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

/*
가장 작은 값 저장해놓고
prices 순회하면서
    더 작은 값 나타나면 대입하고,
    큰 값 나타나면 큰 값에서 가장 작은 값 뺀 결과를 ans랑 비교해서 큰 값 취함

prices 한 번만 순회하면 돼서
시간복잡도는 O(N)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_p = 100000;
        int ans = 0;
        for (auto& p : prices) {
            if (min_p > p)
                min_p = p;
            else if (min_p < p)
                ans = max(ans, p-min_p);
        }
        return ans;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution s1 = Solution();
    int ans = s1.maxProfit(prices);
    printf("%d\n", ans);
}