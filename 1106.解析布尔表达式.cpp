/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 */

// @lc code=start

#include <stack>
#include <string>
using namespace std;

class Solution {
    stack<char> stack;

    void not_operator(const int& True, const int& False) {
        if (False) {
            // origin = False
            // res = True
            stack.push('t');
        } else {
            // origin = True
            // res = False
            stack.push('f');
        }
    }
    void and_operator(const int& True, const int& False) {
        if (False) {
            // False & ... => False
            stack.push('f');
        } else {
            stack.push('t');
        }
    }
    void or_operator(const int& True, const int& False) {
        if (True) {
            // True | ... => True
            stack.push('t');
        } else {
            stack.push('f');
        }
    }
    void operate() {
        int NumOfTrue  = 0;
        int NumOfFalse = 0;
        // Fetch until get `(`
        while (true) {
            char curr_char = stack.top();
            stack.pop();
            if (curr_char == '(') {
                break;
            }
            if (curr_char == 'f') {
                ++NumOfFalse;
            } else if (curr_char == 't') {
                ++NumOfTrue;
            }
        }
        // get operator
        char Operator = stack.top();
        stack.pop();
        // match operator
        switch (Operator) {
        case '&':
            and_operator(NumOfTrue, NumOfFalse);
            break;
        case '|':
            or_operator(NumOfTrue, NumOfFalse);
            break;
        case '!':
            not_operator(NumOfTrue, NumOfFalse);
            break;
        }
    }

public:
    bool parseBoolExpr(const string& expression) {
        bool res = false;
        for (const char& curr_char : expression) {
            if (curr_char == ',') {
                continue;
            }
            if (curr_char == ')') {
                operate();
            } else {
                stack.push(curr_char);
            }
        }
        if (stack.top() == 'f') {
            res = false;
        } else {
            res = true;
        }
        return res;
    }
};
// @lc code=end
