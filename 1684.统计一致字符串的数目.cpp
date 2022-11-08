/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start

#include <algorithm>
#include <array>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int countConsistentStrings(const string& allowed, vector<string>& words) {
        int res = 0;

        unordered_set<char> allowedTable;

        for (const char& curr_char : allowed) {
            allowedTable.insert(curr_char);
        }

        for (string& str : words) {
            bool if_suit = true;
            for (const char& curr_char : str) {
                // do not contain the char
                if (allowedTable.find(curr_char) == allowedTable.end()) {
                    if_suit = false;
                    break;
                }
            }
            if (if_suit) {
                ++res;
            }
        }

        return res;
    }
};
// @lc code=end
