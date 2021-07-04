// https://leetcode.com/problems/two-sum/

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // pair vector for (num, idx)
        vector<pair<int, int>> nums_id_pair;
        for (int i=0; i<nums.size(); i++) {
            nums_id_pair.push_back(make_pair(nums[i], i));
        }
        sort(nums_id_pair.begin(), nums_id_pair.end());

        int left = 0;
        int right = nums_id_pair.size() - 1;
        while (true) {
            int sum = nums_id_pair[left].first + nums_id_pair[right].first;
            if (sum == target)
                break;
            else if (sum < target)
                left++;
            else 
                right--;
        }
        
        vector<int> ans = {nums_id_pair[left].second, nums_id_pair[right].second};
        return ans;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // pair map for (num: idx)
        unordered_map<int, int> idmap;
        
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            int diff = target - nums[i];
            if (idmap.find(diff) != idmap.end()) {
                ans.push_back(i);
                ans.push_back(idmap[diff]);
                break;
            }
            idmap.insert(make_pair(nums[i], i));
        }
        return ans;
    }
};


int main() {
    Solution2 s = Solution2();
    vector<int> nums = {3, 2, 4};
    vector<int> ans = s.twoSum(nums, 6);
    for (auto &num : ans)
        cout << num << endl;
}