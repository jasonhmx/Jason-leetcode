/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
Doesn't seem to work with the return a node recursion method.
Traverse method requires treating the binary tree as a tertiary tree where each node is the space
between nodes
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr || root->left == nullptr){
            return root;
        }
        traverse(root->left, root->right);
        return root;
    }

    void traverse(Node* node1, Node* node2){
        if (node1 == nullptr || node2 == nullptr){
            return;
        }
        node1->next = node2;
        traverse(node1->left, node1->right);
        traverse(node1->right, node2->left);
        traverse(node2->left, node2->right);
    }
};
// @lc code=end

