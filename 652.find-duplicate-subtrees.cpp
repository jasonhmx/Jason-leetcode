/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
The logic for this problem is to use the post-order traversal of the binary tree, obtaining root nodes
for the subtrees, then serialising the tree at the root, and checking if there are repeats in a hashmap
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> map;
        vector<TreeNode*> result;
        traverse(root, map, result);
        return result;
    }

    string traverse(TreeNode* root, unordered_map<string, int>& map, vector<TreeNode*>& result){
        // uses post-order traversal, serialises subtree, adds to map, and appends repetition to result
        if (root == nullptr){
            return ",#";
        }

        string left = traverse(root->left, map, result);
        string right = traverse(root->right, map, result);
        // this needs to be post order as well (not inorder, otherwise there is ambiguity in serialization!!)
        string subtree = left + right + "," + to_string(root->val);
        map[subtree] += 1;
        if(map[subtree] == 2){
            result.push_back(root);
        }
        return subtree;
    }
};
// @lc code=end

