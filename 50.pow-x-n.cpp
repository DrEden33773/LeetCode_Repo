/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start

/// fast traverse
class Solution {
public:
    double quickPow(double x, long long n) {
        double res = 1;
        while (n) {
            if (n & 1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
    double myPow(double x, int n) {
        auto N = static_cast<long long>(n);
        return (N >= 0)
            ? quickPow(x, N)
            : 1.0 / quickPow(x, -N);
    }
};
// @lc code=end
