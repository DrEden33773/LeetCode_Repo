/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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

#include <queue>
#include <utility>

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        // [ TreeNode* ]
        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int curr_level_size = static_cast<int>(queue.size());
            for (int i = 1; i <= curr_level_size; ++i) {
                TreeNode* curr = queue.front();
                queue.pop();

                TreeNode* original_left  = curr->left;
                TreeNode* original_right = curr->right;
                curr->left               = original_right;
                curr->right              = original_left;

                if (curr->left) {
                    queue.push(curr->left);
                }
                if (curr->right) {
                    queue.push(curr->right);
                }
            }
        }

        return root;
    }
};
// @lc code=end
