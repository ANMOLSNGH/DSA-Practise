class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int indx_ = 0;
        for(int i = n-1;i>=1;i--) {
            if(target[i]>target[i-1]) {
                indx_  = i;
                break;
            }
        }
        int cnt = 0;

        for(int i = 0;i<n;i++) {
            if(nums[i]!=target[i]&&indx_>i) return cnt;
            else if(nums[i]!=target[i]) {
                sort(nums.begin()+i,nums.end(),greater<int>());
                if(nums==target) {
                    cnt++;
                    return cnt;
                }
                return 0;
            }
            else if(nums[i]==target[i]) {
                if(indx_<=i) cnt++;
            }
        }
        return cnt;
    } 
};