class Solution {
public:
    int findjustsmaller(vector<int>&nums,int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid]>=target) {
                high = mid-1;
            }
            else {
                low = mid+1;
                ans = nums[mid];
            }
        }
        return ans;
    }
    bool uniformArray(vector<int>& nums1) {
        vector<int>odd_only;
        // vector<int>even_only;
        int n = nums1.size();
        for(auto num:nums1) {
            if(num&1) odd_only.push_back(num); 
        }
        sort(odd_only.begin(),odd_only.end());
        // sort(even_only.begin(),even_only.end());
        bool all_even = true;
        bool all_odd = true;
       
        // case 1 let say all are even.
        for(auto num : nums1) {
             if((num&1)==0) continue;
             else {
                int ans = findjustsmaller(odd_only,num);
                if(ans==-1) {
                    all_even = false;
                    break;
                }
             }
        }
        if(all_even) return true;
    
        for(auto num : nums1) {
        if(num&1) continue;
        else {
        int ans = findjustsmaller(odd_only,num);
        if(ans==-1) {
            all_odd = false;
            break;
           }
        }
      }
      return all_odd;
    }
};