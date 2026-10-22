class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int largest = -1;
        int indx = -1;
        bool sorted_ = true;
        if(n==1) return 0;
        for(int i = 0;i<nums.size();i++) {
            if(i+1<n&&nums[i]>nums[i+1]) sorted_ = false;
            if(nums[i]>largest) {
                largest = nums[i];
                indx = i;
            }
        }

        if(sorted_) return 0;

        bool left_inc = false;
        bool left_dec = false;

        for(int i = 0;i<indx;i++) {
            if(i+1<indx&&nums[i]<nums[i+1]) {
                left_inc = true;
            }

            if(i+1<indx&&nums[i]>nums[i+1]) {
                left_dec = true;
            }
        }

        if(left_inc&&left_dec) return -1;

        bool right_inc = false;
        bool right_dec = false;

        for(int i = indx+1;i<n;i++) {
            if(i+1<n&&nums[i]<nums[i+1]) {
                right_inc = true;
            }
             if(i+1<n&&nums[i]>nums[i+1]) {
                right_dec = true;
            }
        }

        if(right_inc&&right_dec) return -1; 
        if(left_inc&&right_inc) {
            if(nums[0]<nums[n-1]) return -1;
        }

        if(left_dec&&right_dec) {
            if(nums[0]>nums[n-1]) return -1;
        }

        if(!left_inc&&!left_dec&&indx!=0) {
            if(right_inc) {
                if(nums[0]<nums[n-1]) return -1;
            }
            else if(right_dec)  {
                if(nums[0]>nums[n-1]) return -1;
            }
        }

         if(!right_inc&&!right_dec&&indx!=0) {
            if(left_inc) {
                if(nums[0]<nums[n-1]) return -1;
            }
            else if(left_dec)  {
                if(nums[0]>nums[n-1]) return -1;
            }
        }

        int ans = min(indx+1,n-indx+1);
        return ans;

        
    }
};