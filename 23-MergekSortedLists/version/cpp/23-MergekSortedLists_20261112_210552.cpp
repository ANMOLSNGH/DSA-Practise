// Last updated: 11/12/2026, 9:05:52 PM
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
13    ListNode* mergeKLists(vector<ListNode*>& lists) {
14        if(lists.empty()) return nullptr;
15        return sortLL(lists,0,lists.size()-1);
16    }
17
18    ListNode* sortLL(vector<ListNode*>&lists,int start,int end) {
19        if(start==end) return lists[start];
20        int mid = (start + end)/2;
21
22        ListNode* left = sortLL(lists,start,mid);
23        ListNode* right = sortLL(lists,mid+1,end);
24        return mergeLL(left,right);
25    }
26
27     ListNode* mergeLL(ListNode* strt,ListNode* strt_) {
28        ListNode* dummy = new ListNode(-1);
29        ListNode* merged = dummy;
30        while(strt != NULL && strt_ != NULL) {
31            if(strt->val < strt_->val) {
32                merged->next = strt;
33                strt = strt->next;
34            }
35            else {
36                merged->next = strt_;
37                strt_ = strt_->next;
38            }
39            merged = merged->next;
40        }
41
42        if(strt != NULL) merged->next = strt;
43        if(strt_ != NULL) merged->next = strt_;
44
45        ListNode* newHead = dummy->next;
46        delete(dummy);
47        return newHead;
48    }
49};