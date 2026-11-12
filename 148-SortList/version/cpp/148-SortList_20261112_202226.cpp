// Last updated: 11/12/2026, 8:22:26 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* getMid(ListNode* head) {
14        if(!head) return NULL;
15        ListNode* slow = head;
16        ListNode* fast = head;
17        while(fast->next!=NULL&&fast->next->next!=NULL) {
18            slow = slow->next;
19            fast = fast->next->next;
20        }
21        return slow;
22    }
23    ListNode* sortLL(ListNode* head) {
24        if(head==NULL||head->next==NULL) return head;
25        ListNode* mid = getMid(head);
26        ListNode* nextMid = mid->next;
27        mid->next = NULL;
28
29        ListNode* left = sortLL(head);
30        ListNode* right = sortLL(nextMid);
31        return mergeLL(left,right);
32    }
33
34    ListNode* mergeLL(ListNode* strt,ListNode* strt_) {
35        ListNode* dummy = new ListNode(-1);
36        ListNode* merged = dummy;
37        while(strt != NULL && strt_ != NULL) {
38            if(strt->val < strt_->val) {
39                merged->next = strt;
40                strt = strt->next;
41            }
42            else {
43                merged->next = strt_;
44                strt_ = strt_->next;
45            }
46            merged = merged->next;
47        }
48
49        if(strt != NULL) merged->next = strt;
50        if(strt_ != NULL) merged->next = strt_;
51
52        ListNode* newHead = dummy->next;
53        delete(dummy);
54        return newHead;
55    }
56    ListNode* sortList(ListNode* head) {
57        return sortLL(head);
58    }
59};