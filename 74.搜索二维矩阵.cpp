/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int FindSubMatrix(vector<vector<int>>& matrix, int target) {
        int res   = -1;
        int left  = 0;
        int right = static_cast<int>(matrix.size() - 1);
        while (left <= right) {
            int  mid        = (left + right) / 2;
            int& min_of_mid = matrix[mid][0];
            int& max_of_mid = matrix[mid].back();
            if (target > max_of_mid) {
                left = mid + 1;
            } else if (target < min_of_mid) {
                right = mid - 1;
            } else {
                res = mid;
                break;
            }
        }
        return res;
    }
    int Find(vector<int>& nums, int target) {
        int res   = -1;
        int left  = 0;
        int right = static_cast<int>(nums.size() - 1);
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                res = mid;
                break;
            }
        }
        return res;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sub_matrix_idx = FindSubMatrix(matrix, target);
        if (sub_matrix_idx == -1) {
            return false;
        }
        int idx = Find(matrix[sub_matrix_idx], target);
        if (idx == -1) {
            return false;
        }
        return true;
    }
};
// @lc code=end
