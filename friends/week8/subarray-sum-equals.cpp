// https://leetcode.com/problems/subarray-sum-equals-k/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Base {
public:
    virtual int subarraySum(vector<int>& nums, int k) = 0;
};

// TLE
// O(n^2)
class Solution1 : public Base {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            int sum = 0;
            for (int j=i; j<nums.size(); j++) {
                sum += nums[j];
                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
};

// O(n)
class Solution2 : public Base {
public:
    int subarraySum(vector<int>& nums, int k) {
        // i < j
        // sum[j] - sum[i] == k
        // sum[j] - k == sum[i]
        unordered_map<int, int> past_sum;
        past_sum[0] = 1;
        
        int ans = 0;
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            auto past = past_sum.find(sum - k);
            if (past != past_sum.end())
                ans += past->second;
            
            auto now = past_sum.find(sum);
            if (now != past_sum.end())
                past_sum[sum] = now->second + 1;
            else
                past_sum[sum] = 1;
        }
        return ans;
    }
};

int main() {
    Base* s;
    Solution1 s1;
    Solution2 s2;
    
    vector<int> nums = {1, 2, 3};
    int k = 3;

    s = &s1;
    int ret = s->subarraySum(nums, k);
    cout << ret << endl;

    s = &s2;
    ret = s->subarraySum(nums, k);
    cout << ret << endl;
}