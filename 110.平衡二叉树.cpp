/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

#include <cmath>
#include <queue>

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
    int BiTreeDepth_LevelOrder(TreeNode* node) {
        int res = 0;

        if (node == nullptr) {
            return 0;
        }

        std::queue<TreeNode*> queue;
        queue.push(node);

        while (!queue.empty()) {
            int currentLevelSize = static_cast<int>(queue.size());
            // iterate `currentLevel`
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = queue.front();
                queue.pop();
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            // finished iterating `currentLevel`, ++res
            ++res;
        }

        return res;
    }
    bool if_balanced(TreeNode* node) {
        if (node == nullptr) {
            return true;
        }

        std::queue<TreeNode*> queue;
        queue.push(node);

        while (!queue.empty()) {
            int currentLevelSize = static_cast<int>(queue.size());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = queue.front();

                int left_depth  = BiTreeDepth_LevelOrder(node->left);
                int right_depth = BiTreeDepth_LevelOrder(node->right);
                if (std::abs(left_depth - right_depth) > 1) {
                    return false;
                }

                queue.pop();
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
        }
        return true;
    }
    bool isBalanced(TreeNode* root) {
        return if_balanced(root);
    }
};
// @lc code=end
