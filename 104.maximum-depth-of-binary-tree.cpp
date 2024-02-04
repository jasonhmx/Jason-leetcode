/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
using namespace std;


class Solution {
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        traverse(root, 0, result);
        return result;
    }

    void traverse(TreeNode* root, int count, int& result) {
        if (root == nullptr){
            result = max(result, count);
            return;
        }
        count ++;
        traverse(root->left, count, result);
        traverse(root->right, count, result);
    }
};
// @lc code=end

