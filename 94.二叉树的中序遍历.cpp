/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr) { }
    explicit TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr) { }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right) { }
};

class Solution {
public:
    void PostOrderRec(vector<int>& vec, TreeNode* node) {
        if (node) {
            PostOrderRec(vec, node->left);
            vec.push_back(node->val);
            PostOrderRec(vec, node->right);
        }
    }
    void InOrderIter(vector<int>& vec, TreeNode* node) {
        stack<TreeNode*> stack;
        while (node || !stack.empty()) {
            // iterate all left sub tree
            while (node) {
                stack.push(node);
                node = node->left;
            } // now node == nullptr
            // backtrace
            node = stack.top();
            stack.pop();
            // operate
            vec.push_back(node->val);
            // go to right sub tree
            node = node->right;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        auto res = vector<int>();
        InOrderIter(res, root);
        return res;
    }
};
// @lc code=end
