class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans = 0;

        for(int i = 0;i<rocks.size();i++) {
            if((capacity[i]-rocks[i])==0) {
                ans++;
                continue;
            }
            else pq.push(capacity[i]-rocks[i]);
        }

        while(!pq.empty()&&add!=0) {
            int val = pq.top();
            if(val>add) break;

            else {
                add -= val;
                ans++;
            }
            pq.pop();
        }
        return ans;
    }
};