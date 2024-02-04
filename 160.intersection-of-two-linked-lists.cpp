/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        while(p != nullptr && q!=nullptr){
            p = p->next;
            q = q->next;
        }
        if (p == nullptr){
            p = headB;
        }
        if (q == nullptr){
            q = headA;
        }
        while(p != nullptr && q!=nullptr){
            p = p->next;
            q = q->next;
        }
        if (p == nullptr){
            p = headB;
        }
        if (q == nullptr){
            q = headA;
        }
        while(p != q && p!=nullptr && q!=nullptr){
            p = p->next;
            q = q->next;
        }
        if (p == nullptr || q == nullptr){
            return nullptr;
        } else {
            return p;
        }
    }
};
// @lc code=end

