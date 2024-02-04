/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
class Solution {
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        // the longest path through each node is the depth left + depth right
        // calculate the longest path that pass through each node, and update the result
        int maxDiameter = 0;
        maxDepth(root, maxDiameter);
        return maxDiameter;
    }

    int maxDepth(TreeNode* root, int& maxDiameter) {
        if (root == nullptr) {
            return 0;
        }
        int leftMax = maxDepth(root->left, maxDiameter);
        int rightMax = maxDepth(root->right, maxDiameter);
        // calculate diameter from post-order position
        int myDiameter = leftMax + rightMax;
        maxDiameter = max(maxDiameter, myDiameter);
        return 1 + max(leftMax, rightMax);
    }
};
// @lc code=end

