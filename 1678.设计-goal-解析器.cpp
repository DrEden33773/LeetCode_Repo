/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start

#include <stack>
#include <string>
using namespace std;

class Solution {
    stack<char> stack;
    string      res;

public:
    void operate() {
        bool if_empty_column = true;
        while (true) {
            char curr_char = stack.top();
            stack.pop();
            if (curr_char == '(') {
                break;
            } else {
                if_empty_column = false;
            }
        }
        if (if_empty_column) {
            res += 'o';
        } else {
            res += "al";
        }
    }
    string interpret(const string& command) {
        for (const char& curr_char : command) {
            if (curr_char != ')') {
                if (curr_char != 'G') {
                    stack.push(curr_char);
                } else {
                    res += 'G';
                }
            } else {
                operate();
            }
        }
        return res;
    }
};
// @lc code=end
