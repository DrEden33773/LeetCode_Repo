/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start

#include <algorithm>
#include <vector>
using namespace std;

// DFS + CuttingEdges => Negative

class Solution {
    vector<int> prefix;
    int         answer = 0;
    int         size   = 0;

public:
    void DFS(const int& idx, const int& curr_sub) {
        if (idx == size) {
            return;
        }
        // cutting edge
        int remaining = (idx == 0)
            ? prefix[size - 1]
            : prefix[size - 1] - prefix[idx - 1];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;

        size = static_cast<int>(nums.size());
        sort(
            nums.begin(),
            nums.end(),
            [](const int& a, const int& b) {
                return a < b;
            }
        );

        prefix    = vector<int>(nums.size(), 0);
        prefix[0] = nums[0];
        for (int idx = 1; idx < nums.size(); ++idx) {
            prefix[idx] = nums[idx] + prefix[idx - 1];
        }

        return res;
    }
};
// @lc code=end
