class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi_ans = 0;
        
        int i = 0;
        while (i < n) {
            long long rem = nums[i] % k;
            int start = i;
            
            while (i < n && nums[i] % k == rem) {
                i++;
            }
            
            long long total = i - start;
            
            if (rem == 0) {
                maxi_ans = max(maxi_ans, (int)total);
            } 
            else {
                long long total_sum = total * rem; 
                long long lcmi = lcm(rem, (long long)k);
                
                long long maxi_sum = (total_sum / lcmi) * lcmi;
                long long maxi_num = 0;
                
                if (maxi_sum == total_sum) {
                    maxi_sum -= lcmi;
                    if (maxi_sum >= 0) {
                        maxi_num = maxi_sum / rem;
                        maxi_num++;
                    }
                }
                else if (maxi_sum >= 0) {
                    maxi_num = maxi_sum / rem;
                    maxi_num++;
                }
                
                maxi_ans = max(maxi_ans, (int)maxi_num);
            }
        }
        
        return maxi_ans;
    }
};