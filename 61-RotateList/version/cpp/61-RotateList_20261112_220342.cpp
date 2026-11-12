// Last updated: 11/12/2026, 10:03:42 PM
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
13    /*
14     Step 1) Reverse entire LL
15     Step 2) Reverse till k nodes
16     Step 3) Reverse from k+1 nodes till end nodes
17    */
18    ListNode* rotateRight(ListNode* head, int k) {
19        if (!head || !head->next || k == 0) return head;
20
21        int n = 1;
22        ListNode* tail = head;
23        while (tail->next) {
24            tail = tail->next;
25            n++;
26        }
27
28        k = k % n;
29        if (k == 0) return head;
30
31        tail->next = head;
32
33        int steps = n-k-1;
34        ListNode* newTail = head;
35        while (steps--) {
36            newTail = newTail->next;
37        }
38
39        ListNode* newHead = newTail->next;
40        newTail->next = nullptr;
41
42        return newHead;
43    }
44};