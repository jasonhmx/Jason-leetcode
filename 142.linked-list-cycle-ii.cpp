/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meet = nullptr;
        while(fast != nullptr){
            slow = slow -> next;
            if (fast -> next == nullptr){
                return nullptr;
            }
            fast = fast -> next -> next;
            if (slow == fast){
                meet = slow;
                break;
            }
        }
        if (meet != nullptr){
            slow = head;
            while(fast != slow){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        // no cycle
        return nullptr;
    }
};
// @lc code=end

