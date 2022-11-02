/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        res.reserve(points.size());

        sort(
            points.begin(),
            points.end(),
            [](
                const vector<int>& a,
                const vector<int>& b
            ) {
                return (a[0] * a[0] + a[1] * a[1])
                    < (b[0] * b[0] + b[1] * b[1]);
            }
        );

        for (int i = 0; i < k; ++i) {
            res.emplace_back(points[i]);
        }

        return res;
    }
};
// @lc code=end
