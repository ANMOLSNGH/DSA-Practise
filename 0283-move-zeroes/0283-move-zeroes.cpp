class Solution {
public:
    void moveZeroes(vector<int>& nums) {
          ios::sync_with_stdio(false);
          cin.tie(NULL);
          int cnt_0 = 0;
          for(auto num : nums) {
            if(num==0) cnt_0++;
          }
          int i = 0;
          for(auto num : nums) {
            if(num!=0) {
                nums[i++] = num;
            }
          }
          while(cnt_0!=0) {
            nums[i++] = 0;
            cnt_0--;
          }
    }
};