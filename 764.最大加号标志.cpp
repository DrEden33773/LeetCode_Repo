/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 */

// @lc code=start

#include <algorithm>
#include <initializer_list>
#include <vector>
using namespace std;

class Solution {
    using IntMatrix = vector<vector<int>>;
    using IntVec    = vector<int>;

public:
    int  answer = 0;
    void BFS_Operate(const int& layer, IntMatrix& Mat) {
        const int& size = static_cast<int>(Mat.size());
        for (int idx = layer; idx < size - layer; ++idx) {
            auto updater = [&Mat](int row, int col) {
                if (!Mat[row][col]) {
                    return;
                }
                initializer_list<int> list = {
                    Mat[row - 1][col],
                    Mat[row + 1][col],
                    Mat[row][col - 1],
                    Mat[row][col + 1],
                };
                int MIN       = min(list);
                Mat[row][col] = MIN + 1;
            };
        }
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if (n == 1) {
            return (mines.empty()) ? 1 : 0;
        }
        int       size = static_cast<int>(mines.size());
        IntMatrix Mat  = IntMatrix(size, IntVec(size, 1));
        // 1. put zero
        for (const vector<int>& pair : mines) {
            const int& row = pair[0];
            const int& col = pair[1];
            Mat[row][col]  = 0;
        }
        // 2. BFS
        for (int layer = 1; layer < (size / 2); ++layer) {
            BFS_Operate(layer, Mat);
        }
        return answer;
    }
};
// @lc code=end
