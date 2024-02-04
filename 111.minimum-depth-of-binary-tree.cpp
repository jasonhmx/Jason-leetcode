/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
Classic BFS, except we never run into same node twice, so no need for visited set
*/

#include <queue>
using namespace std;

class Solution {
public:
    int depth = 1;
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        bfs(root, depth);
        return depth;
    }

    void bfs(TreeNode* root, int& depth){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){ // sz here is the number of nodes in that current level
                TreeNode* current = q.front();
                q.pop();
                if (current->left == nullptr && current->right == nullptr){
                    return;
                }
                if (current->left != nullptr){
                    q.push(current->left);
                } 
                if (current->right != nullptr){
                    q.push(current->right);
                }
            }
            depth++;
        }
    }
};
// @lc code=end

