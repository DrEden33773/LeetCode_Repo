/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int FindFirst(vector<int>& nums, int target) {
        int res_idx = static_cast<int>(nums.size());

        int left  = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                res_idx = min(res_idx, mid);
                right   = mid - 1;
            }
        }

        if (res_idx == static_cast<int>(nums.size())) {
            res_idx = -1;
        }

        return res_idx;
    }
    int FindLast(vector<int>& nums, int target) {
        int res_idx = -1;

        int left  = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                res_idx = max(res_idx, mid);
                left    = mid + 1;
            }
        }

        return res_idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = vector<int>(2, -1);

        if (nums.empty()) {
            return res;
        }

        res[0] = FindFirst(nums, target);
        res[1] = FindLast(nums, target);

        return res;
    }
};
// @lc code=end
