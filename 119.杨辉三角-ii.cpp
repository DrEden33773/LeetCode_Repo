/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start

#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = vector<int>(rowIndex + 1, 1);
        if (!rowIndex) {
            return res;
        }
        return res;
    }
};
// @lc code=end
