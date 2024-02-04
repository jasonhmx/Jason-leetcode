/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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

*/

#include <unordered_map>
using namespace std;


class Solution {
public:
    
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int lo, int hi) {
        // essentially, build trees between lo and hi
        // for every node between lo and hi, use it as root, build up the tree
        vector<TreeNode*> result;
        if (lo > hi){
            result.push_back(nullptr);
            return result;
        }

        for (int i = lo; i <= hi; i++){
            vector<TreeNode*> left = build(lo, i-1);
            vector<TreeNode*> right = build(i+1, hi);
            for (int j = 0; j < left.size(); j++){
                for (int k = 0; k < right.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
// @lc code=end

