/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 1) {
            return (nums[0] >= target) ? 1 : 0;
        }

        int res = 0;

        return res;
    }
};
// @lc code=end
