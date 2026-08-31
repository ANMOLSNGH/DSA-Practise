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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>indx_store;
        ListNode* ptr = head->next;
        ListNode* prev = head;
        int cnt = 1;
        while(ptr->next!=NULL) {
            if((ptr->val>prev->val&&ptr->val>ptr->next->val)||(ptr->val<prev->val&&ptr->val<ptr->next->val)) {
                   indx_store.push_back(cnt);
            }         
            prev = ptr;
            ptr = ptr->next;
            cnt++;
        }
        int mini = INT_MAX;
        int maxi = 0;
        if(indx_store.size()<=1) return {-1,-1};
        for(int i = 1;i<indx_store.size();i++) {
            mini = min(mini,indx_store[i]-indx_store[i-1]);
        }
        maxi  = indx_store[indx_store.size()-1] - indx_store[0];
        return {mini,maxi};
    }
};