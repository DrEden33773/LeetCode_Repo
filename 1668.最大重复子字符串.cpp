/*
 * @lc app=leetcode.cn id=1668 lang=cpp
 *
 * [1668] 最大重复子字符串
 */

#include <algorithm>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    // sequence => ababc
    // word => ab
    int maxRepeating(const string& sequence, const string& word) {
        int res = 0;
        if (word.size() > sequence.size()) {
            return 0;
        }
        int seq_size          = static_cast<int>(sequence.size());
        int word_size         = static_cast<int>(word.size());
        int remained_seq_size = seq_size;
        for (int i = 0; i < seq_size; ++i) {
            if (remained_seq_size < word_size) {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
