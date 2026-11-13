/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1) return head;
        
        int len = 0;
        ListNode* dummy = head;
        while (dummy) {
            len++;
            dummy = dummy->next;
        }
        
        int div = len / k;
        ListNode* hold = nullptr;
        ListNode* curr = head;
        ListNode* newHead = nullptr;
        while(curr&&div--) {
            ListNode* prev = nullptr;
            ListNode* groupTail = curr;
            ListNode* ahead = curr->next;
            int cnt = 0;
            while (curr && cnt != k) {
                curr->next = prev;
                prev = curr;
                curr = ahead;
                if(ahead) ahead = ahead->next;
                cnt++;
            }
            if(!newHead) newHead = prev;
            else hold->next = prev;
            hold = groupTail;

            if(hold) hold->next = curr;
        }
        return newHead;
    }
};