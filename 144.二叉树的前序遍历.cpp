/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
            vec.push_back(node->val);
            PostOrderRec(vec, node->left);
            PostOrderRec(vec, node->right);
        }
    }
    void PreOrderIter(vector<int>& vec, TreeNode* node) {
        stack<TreeNode*> stack;
        while (node || !stack.empty()) {
            // iterate all left sub tree
            while (node) {
                // operate
                vec.push_back(node->val);
                // store
                stack.push(node);
                // go left
                node = node->left;
            }
            // trace back
            node = stack.top();
            stack.pop();
            // go to right sub tree
            node = node->right;
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        auto res = vector<int>();
        PreOrderIter(res, root);
        return res;
    }
};
// @lc code=end
