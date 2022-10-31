/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int       val {};
    TreeNode* left {};
    TreeNode* right {};
    explicit TreeNode(int x)
        : val(x) { }
};

class Codec {
    // LevelOrder, with `nullptr` as `#`
public:
    // Encodes a tree to a single string.
    vector<vector<string>> serialize(TreeNode* node) {
        vector<vector<string>> res;

        // special case
        if (!node) {
            return res;
        }

        queue<TreeNode*> queue;
        queue.push(node);

        while (!queue.empty()) {
            int currentLevelSize = static_cast<int>(queue.size());
            res.push_back(vector<string>());
            for (int i = 1; i <= currentLevelSize; ++i) {
                // get node
                auto node = queue.front();
                // if get nullptr node
                if (!node) {
                    queue.pop();
                    res.back().push_back("#");
                    continue;
                }
                // remove the node from queue
                queue.pop();
                // insert node->val to latest layer_vec
                res.back().push_back(to_string(node->val));
                // join node->left and node->right (include nullptr)
                queue.push(node->left);
                queue.push(node->right);
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const vector<vector<string>>& data) {
        TreeNode* root = nullptr;

        if (data.empty()) {
            return nullptr;
        }

        queue<TreeNode*> queue;
        bool             if_insert_to_left         = true;
        TreeNode*        the_parent                = nullptr;
        int              num_of_inserted_to_parent = -1;

        for (const vector<string>& layer : data) {
            for (const string& node_info : layer) {
                TreeNode* curr_node = (node_info == "#")
                    ? nullptr
                    : new TreeNode(stoi(node_info));

                queue.push(curr_node);

                if (num_of_inserted_to_parent == 2) {
                    // need to update parent
                    do {
                        queue.pop();
                        the_parent = queue.front();
                    } while (!the_parent);
                    num_of_inserted_to_parent = 0;
                }

                if (!the_parent) {
                    root       = curr_node;
                    the_parent = curr_node;
                } else {
                    if (if_insert_to_left) {
                        the_parent->left = curr_node;
                    } else {
                        the_parent->right = curr_node;
                    }
                    if_insert_to_left = !if_insert_to_left;
                }

                ++num_of_inserted_to_parent;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
