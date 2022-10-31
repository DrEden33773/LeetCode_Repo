/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历（从左到右）
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

#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
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
    void hash_level_order(vector<vector<int>>& res, TreeNode* root) {
        // [ (curr_layer_num , node) ]
        queue<pair<int, TreeNode*>> queue;
        // {layer : [ nodes ] }
        unordered_map<int, vector<int>> hashmap;

        queue.push(make_pair(1, root));
        int max_layer = 1;

        while (!queue.empty()) {
            int       curr_layer = queue.front().first;
            TreeNode* node       = queue.front().second;

            hashmap[curr_layer].push_back(node->val);
            max_layer = max(max_layer, curr_layer);

            if (node->left) {
                queue.push(make_pair(curr_layer + 1, node->left));
            }
            if (node->right) {
                queue.push(make_pair(curr_layer + 1, node->right));
            }
            queue.pop();
        }

        for (int layer = 1; layer <= max_layer; ++layer) {
            res.push_back(hashmap[layer]);
        }
    }
    void emplace_level_order(vector<vector<int>>& res, TreeNode* root) {
        // [ (curr_layer_num , node) ]
        queue<pair<int, TreeNode*>> queue;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root) {
            return res;
        }
        hash_level_order(res, root);

        return res;
    }
};
// @lc code=end
