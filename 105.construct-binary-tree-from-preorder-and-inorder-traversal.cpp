/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
Think about structure of the traversal orders. For preorder, the structure is root, leftTree, rightTree;
for in-order, it is leftTree, root, rightTree. Pick out root first from preorderList, use inorderList to determine
whether the node is in leftTree or rightTree, since root partitions these in inorderList. Divide preorderList into root,
leftTree, rightTree; then run construction on the subtrees again.

This can actually be made simpler, because with the index of root in inorderList,
we can determine the size of the leftTree and rightTree, so we don't have to use the while loop
to go through the elements to find rightStart.
*/
#include <unordered_map>
using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // what we need to do:
        // identify root using preorder vector
        // identify elements of the left and right subtree using inorder vector
        // construct left and right subtree recursively, attach to root as children
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++){
            inorderMap.emplace(inorder[i], i);
        }

        return buildWithBounds(preorder, inorderMap, inorder, 0, preorder.size()-1);
    }

    TreeNode* buildWithBounds(vector<int>& preorder, unordered_map<int, int> &inorderMap, vector<int>& inorder, int lo, int hi){
        // lo and hi are the indices of preorder vector we are interested in.
        // also need to consider inorder val lo and hi
        if (lo > hi){
            return nullptr;
        }
        int rootVal = preorder[lo];
        TreeNode* root = new TreeNode(rootVal);
        int rootIdx = inorderMap[rootVal];
        // anything smaller than rootIdx belong in left subtree, otherwise right subtree
        int leftStart = lo + 1;
        int rightStart = lo + 1;
        while(rightStart <= hi && inorderMap[preorder[rightStart]] < rootIdx){
            rightStart++;
        }
        // now, leftstart is the starting index for the left subtree, rightstart is starting index of right subtree
        root->left = buildWithBounds(preorder, inorderMap, inorder, leftStart, rightStart-1);
        root->right = buildWithBounds(preorder, inorderMap, inorder, rightStart, hi);
        return root;
    }
};
// @lc code=end

