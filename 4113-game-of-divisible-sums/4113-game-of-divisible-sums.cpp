class Solution {
public:
    typedef long long ll;
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        ll curr_state = 0;
        ll dp_next = 0;
        ll dp_nnext = 0;
        for(int i = n-1;i>=0;i--) {
            ll sum1 = nums[i];
            ll take1 = sum1;

            if(sum1%3==0) {
                take1 -= dp_next;
            }
            else take1 += dp_next;

            // case 2 

            ll max_gain = take1;
            if(i+1<n) {
                ll sum2 = nums[i] + nums[i+1];
                ll take2 = sum2;

                if(sum2%3==0) {
                    take2 -= dp_nnext;
                }
                else take2 += dp_nnext;
                max_gain = max(take1,take2);
            }
            curr_state = max_gain;

            dp_nnext = dp_next;
            dp_next = curr_state;
        }
        return curr_state;
    }
};