/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
For deletion, if on leaf just delete. If not, swap with smallest from right subtree
or biggest from left subtree, then delete the end node. Pay attention to the swapping 
and assignment operations.
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // basecase: if root == nullptr, return nullptr
        if (root == nullptr){
            return nullptr;
        }
        if (key < root->val){
            root->left = deleteNode(root->left, key);
        } else if (key > root->val){
            root->right = deleteNode(root->right, key);
        } else { // key == root->val
            // find min on right subtree
            if(root->left == nullptr){
                return root->right;
            }
            if(root->right == nullptr){
                return root->left;
            } // these two cover the case where root doesn't have any children
            TreeNode* minNode = findMin(root->right);

            // here we need to first delete minNode from right subtree, then assign
            // original subtrees to minNode. Otherwise the node will be deleted after
            // assignment
            root->right = deleteNode(root->right, minNode->val);
            minNode->left = root->left;
            minNode->right = root->right;
            // DON'T FORGET TO REASSIGN ROOT TO MINNODE!!
            root = minNode;
        }
        return root;
    }

    TreeNode* findMin(TreeNode* root){ // doesn't work on nullptr
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
};
// @lc code=end

