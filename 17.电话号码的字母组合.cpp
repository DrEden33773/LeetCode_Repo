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

        queue<string> the_queue;
        string        front_str;

        for (const char& letter : digits) {
            string& curr_comb = map[letter];

            size_t the_front_str_size = the_queue.front().size();
            while (the_queue.front().size() <= the_front_str_size) {
                if (!the_queue.empty()) {
                    front_str = the_queue.front();
                    the_queue.pop();
                }
                for (const char& curr_char : curr_comb) {
                    string to_push = front_str + curr_char;
                    the_queue.push(to_push);
                }
            }
        }

        while (!the_queue.empty()) {
            res.push_back(the_queue.front());
            the_queue.pop();
        }

        return res;
    }
};
// @lc code=end
