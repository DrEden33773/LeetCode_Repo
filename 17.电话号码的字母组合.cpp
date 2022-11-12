/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string& digits) {
        vector<string> res;

        if (digits.empty()) {
            return res;
        }

        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";

        queue<string> queue;

        // 1. init the queue
        for (const auto& curr_char : map[digits[0]]) {
            string toPush;
            toPush += curr_char;
            queue.push(toPush);
        }

        // 2. bfs
        for (size_t i = 1; i < digits.size(); ++i) {
            const string& curr_comb       = map[digits[i]];
            size_t        curr_level_size = queue.size();
            while (curr_level_size--) {
                for (auto& curr_char : curr_comb) {
                    string toPush = queue.front() + curr_char;
                    queue.push(toPush);
                }
                queue.pop();
            }
        }

        // 3. export the queue
        while (!queue.empty()) {
            res.push_back(queue.front());
            queue.pop();
        }

        return res;
    }
};
// @lc code=end
