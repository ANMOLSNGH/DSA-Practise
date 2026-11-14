class Solution {
public:
    typedef long long ll;
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll>pref(n);
        pref[0] = nums[0];
        for(int i = 1;i<n;i++) pref[i] = nums[i] + pref[i-1];
        auto rangeSum = [&](int i,int j) -> long long {
            if(i>j) return 0;
            return pref[j]- ((i>0) ?pref[i-1]:0);
        };
        vector<int>nge(n,n);
        stack<int>st;
        for(int i = n-1;i>=0;i--) {
            while(!st.empty()&&nums[st.top()]<nums[i]){
                st.pop();
            }
            nge[i] = st.empty()?n:st.top();
            st.push(i);
        }

        vector<ll>ops(n+1,0);

        for(int i = n-1;i>=0;i--) {
            int m = nge[i];

            ll segOps = (1LL*nums[i]*(m-i)) - rangeSum(i,m-1);
            ops[i] = segOps + ops[m];
        }

        //Sliding window maxm sum in subarray
        deque<int>dq;
        ll res = 0;
        int i = 0;
        int j = 0;
        while(j<n) {
            while(!dq.empty()&&nums[dq.back()]<nums[j]) dq.pop_back();
            dq.push_back(j);

            while(i<=j) {
                ll m = dq.front();
                ll opscnt = ops[i] - ops[m] + (1LL*nums[m]*(j-m+1)) - rangeSum(m,j);

                if(opscnt<=k) break;

                i++;
                if(dq.front()<i) dq.pop_front();
            }
            res += (j-i+1);
            j++;
        }
        return res;


    }
};