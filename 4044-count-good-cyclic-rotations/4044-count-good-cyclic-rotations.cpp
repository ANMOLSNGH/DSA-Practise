class Solution {
public:
    typedef long long ll;
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        ll  total_sum = accumulate(nums.begin(),nums.end(),0ll);
        int i = 0;
        int j = n/2-1;
        ll sum = 0;
        ll cnt = 0;
        if(n==2&&nums[0]!=nums[1]) return 1;
        for(;i<=j;i++) sum += nums[i];
        if(sum>(total_sum-sum)) cnt++;
        i=0;
        j++;
        while(j<n) {
            sum += nums[j];
            sum -= nums[i];
            if(sum>(total_sum-sum)) cnt++;
            i++;
            j++;
        }
        sum -= nums[i++];
        j = i;
        sum += nums[0];
        i = 0;
        if(sum>total_sum-sum) cnt++;
        i++;
        while(i<n/2-1) {
            sum += nums[i++];
            sum -= nums[j++];
            if(sum>total_sum-sum) cnt++;
        }
         return cnt;
    }
};