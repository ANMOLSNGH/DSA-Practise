// Last updated: 8/31/2026, 7:24:06 PM
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
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14        vector<int>indx_store;
15        ListNode* ptr = head->next;
16        ListNode* prev = head;
17        int cnt = 1;
18        while(ptr->next!=NULL) {
19            if((ptr->val>prev->val&&ptr->val>ptr->next->val)||(ptr->val<prev->val&&ptr->val<ptr->next->val)) {
20                   indx_store.push_back(cnt);
21            }         
22            prev = ptr;
23            ptr = ptr->next;
24            cnt++;
25        }
26        int mini = INT_MAX;
27        int maxi = 0;
28        if(indx_store.size()<=1) return {-1,-1};
29        for(int i = 1;i<indx_store.size();i++) {
30            mini = min(mini,indx_store[i]-indx_store[i-1]);
31        }
32        maxi  = indx_store[indx_store.size()-1] - indx_store[0];
33        return {mini,maxi};
34    }
35};