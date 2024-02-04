/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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

/*
Notes:
Logic is to get the nodes of the flattened subtrees. But the function signature doesn't have to return a treenode.
Use void to operate on subtrees, then use the values of the children.
Flatten left and right subtrees first, reorder, then traverse the list again to link the two
*/

#include<stack>
using namespace std;

class Solution {
public:
    
    void flatten(TreeNode* root) {
        if (root == nullptr){
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        root->right = left;

        TreeNode* p = root;
        while(p->right != nullptr){
            p = p->right;
        }
        p->right = right;
    }

};
// @lc code=end

