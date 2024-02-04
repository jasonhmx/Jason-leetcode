/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
Use boundaries to keep track of which parts of the nums vector is accessed. Because we want to maintain the left and rightness of 
the original vector, we need to keep it in place without sorting it.
*/
#include<vector>
using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }

    TreeNode* build(vector<int>& nums, int lo, int hi){
        if (lo > hi){
            return nullptr;
        }
        //find index of biggest element
        int idx = -1;
        int maxVal = -1;
        for (int i = lo; i <= hi; i++){
            if (nums[i] > maxVal){
                maxVal = nums[i];
                idx = i;
            }
        }
        TreeNode* root = new TreeNode(maxVal);

        root->left = build(nums, lo, idx-1);
        root->right = build(nums, idx+1, hi);
        return root;
    }
};
// @lc code=end

