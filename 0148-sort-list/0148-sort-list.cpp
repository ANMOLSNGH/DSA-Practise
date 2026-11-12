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
    ListNode* getMid(ListNode* head) {
        if(!head) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL&&fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortLL(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* mid = getMid(head);
        ListNode* nextMid = mid->next;
        mid->next = NULL;

        ListNode* left = sortLL(head);
        ListNode* right = sortLL(nextMid);
        return mergeLL(left,right);
    }

    ListNode* mergeLL(ListNode* strt,ListNode* strt_) {
        ListNode* dummy = new ListNode(-1);
        ListNode* merged = dummy;
        while(strt != NULL && strt_ != NULL) {
            if(strt->val < strt_->val) {
                merged->next = strt;
                strt = strt->next;
            }
            else {
                merged->next = strt_;
                strt_ = strt_->next;
            }
            merged = merged->next;
        }

        if(strt != NULL) merged->next = strt;
        if(strt_ != NULL) merged->next = strt_;

        ListNode* newHead = dummy->next;
        delete(dummy);
        return newHead;
    }
    ListNode* sortList(ListNode* head) {
        return sortLL(head);
    }
};