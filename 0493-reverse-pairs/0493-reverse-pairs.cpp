class Solution {
public:
    
    int cnt = 0;
    void merge(int low,int mid,int high,vector<int>&nums) {
         int n1 = mid-low+1;
         int n2= high-mid;
         vector<int>a(n1),b(n2);
         for(int i = 0;i<n1;i++) a[i] = nums[i+low]; 
         for(int j = 0;j<n2;j++) b[j] = nums[j+mid+1];

         int i = n1-1;
         int j = n2-1;
         while(i>=0&&j>=0) {
            if(a[i]>2LL*b[j]) {
                cnt += j+1;
                i--;
            }
            else {
                j--;
            }
         }
         
          i = 0;
          j = 0;
         int k = low;
         while(i<n1&&j<n2) {
            if(a[i]>b[j]) {
                nums[k++] = b[j++];
            }
            else {
                nums[k++] = a[i++];
            }
         }

         while(i<n1) nums[k++] = a[i++];
         while(j<n2) nums[k++] = b[j++];

    }
    void ms(int low,int high,vector<int>&nums) {
        if(low>=high) return;
        int mid = low + (high-low)/2;

        ms(low,mid,nums);
        ms(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
    int reversePairs(vector<int>& nums) {
        cnt = 0;
         ms(0,nums.size()-1,nums);
         return cnt;
    }
};