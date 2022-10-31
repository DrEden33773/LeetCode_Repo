/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <utility>
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
            PostOrderRec(vec, node->right);
            vec.push_back(node->val);
        }
    }
    void PostOrderIter(vector<int>& vec, TreeNode* node) {
        // [ (if_visited_right, TreeNode*) ]
        stack<pair<bool, TreeNode*>> stack;
        while (node || !stack.empty()) {
            // iterate all left sub tree
            while (node) {
                stack.push(make_pair(false, node));
                node = node->left;
            }
            // back trace
            auto& ref_node_status_pair = stack.top();
            node                       = ref_node_status_pair.second;
            // judge if visited right
            if (!ref_node_status_pair.first) {
                // haven't visited
                ref_node_status_pair.first = true;
                node                       = node->right;
            } else {
                // have visited

                // operate
                vec.push_back(node->val);
                // pop
                stack.pop();
                // escape next `iterate all left sub tree`
                node = nullptr;
            }
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        auto res = vector<int>();
        PostOrderIter(res, root);
        return res;
    }
};
// @lc code=end
