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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return sortLL(lists,0,lists.size()-1);
    }

    ListNode* sortLL(vector<ListNode*>&lists,int start,int end) {
        if(start==end) return lists[start];
        int mid = (start + end)/2;

        ListNode* left = sortLL(lists,start,mid);
        ListNode* right = sortLL(lists,mid+1,end);
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
};