/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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

/*
Notes:
base case: root == null, return null
if root is p or q, root is so far the common ancester. Because:
    if q or p that's not root is in the same branch, it'll eventually be found when it recurses up
    if p or q is in a different branch, following logic will return the ancestor
get the LCA for the two children first, decide what to do
*/

#include <utility>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return nullptr;
        }

        if (root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // left or right can either be: null or p or q. root returns null or p or q or root itself
        // if root itself is returned it doesn't have to iterate through everything
        
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        // if root isn't p or q, neither right or left are nullptrs, that means right and left will each
        // have p and q, and root is the common ancestor
        return root;

    }

};
// @lc code=end

