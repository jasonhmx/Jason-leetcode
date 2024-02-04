/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
This isn't currently working correctly but the main idea is there.
For serialisation: preorder traversal with null node info. Use stringstream

For deserialisation: think traversal as well; trick is to convert ss into list,
pop off each list node as we build up the tree.
*/
#include <string>
#include <sstream>
#include <list>
using namespace std;


class Codec {
public:

    // 代表分隔符的字符
    string SEP = ",";
    // 代表 null 空指针的字符
    string nullNode = "#";
    // 用于拼接字符串
    stringstream ss;

    /* 将二叉树打平为字符串 */
    void traverse(TreeNode* root, stringstream& ss) {
        if (root == nullptr) {
            ss << nullNode << SEP;
            return;
        }

        /****** 前序位置 ******/
        ss << root->val << SEP;
        /***********************/

        traverse(root->left, ss);
        traverse(root->right, ss);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        traverse(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> nodes;
        stringstream ss(data);
        string item; // for storing the current node value
        int length = data.size();
        while(getline(ss, item, ',')) {
            nodes.push_back(item);
        }
        return deserialize(nodes);
    }

    TreeNode* deserialize(list<string> nodes) {// overloaded to operate on nodes
        if(nodes.empty()){
            return nullptr;
        }
        string first = nodes.front();
        if(first == nullNode){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(first));
        nodes.pop_front();
        root->left = deserialize(nodes);
        root->right = deserialize(nodes);
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

