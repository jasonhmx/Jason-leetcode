/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
Due to completeness, this algorithm should have a complexity of 
O(logN * logN), where we try to get down to the left subtree that's 
filled, and add everything else together, as per the code below.
*/
#include <cmath>
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        TreeNode* l = root;
        TreeNode* r = root;
        int hl = 0, hr = 0;
        while (l != nullptr){
            l = l->left;
            hl++;
        }
        while (r != nullptr){
            r = r->right;
            hr++;
        }
        if (hl == hr){
            return pow(2, hl) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
// @lc code=end

