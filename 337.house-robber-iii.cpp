/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
A bit of an awkward serialisation/memoization. If only there is a way to serialise the pointer
and the boolean value together.
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<TreeNode*, vector<int>> memo;
    int rob(TreeNode* root){
        return traverse(root, true);
    }

    int traverse(TreeNode* root, bool canRob){
        // max money at root is
        // if can rob, max(rob root + max money of cannot rob children, not rob root + canrob children)
        // if can't rob, max(canrobchildren)
        if(root == nullptr){
            return 0;
        }
        if(memo.count(root) && memo[root][canRob] != -1){
            return memo[root][canRob];
        }
        int res = 0;
        if(canRob){
            int rob = root->val + traverse(root->left, false) + traverse(root->right, false);
            int skip = traverse(root->left, true) + traverse(root->right, true);
            res = max(rob, skip);
            if(memo.count(root)){
                memo[root][canRob] = res;
            } else{
                memo[root] = {-1, res};
            }
        } else { // cannot rob root
            res = traverse(root->left, true) + traverse(root->right, true);
            if(memo.count(root)){
                memo[root][canRob] = res;
            } else {
                memo[root] = {res, -1};
            }
        }
        return res;
    }
};
// @lc code=end

