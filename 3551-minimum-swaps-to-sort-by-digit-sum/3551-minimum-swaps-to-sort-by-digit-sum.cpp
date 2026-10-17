class Solution {
public:
    int getSum(int num1) {
        int sum = 0;
        while(num1) {
            sum += num1%10;
            num1 /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>afterSorted;
        for(int i = 0;i<n;i++) {
            afterSorted.push_back({nums[i],i});
        }

        auto srt = [&](pair<int,int>&n1,pair<int,int>&n2) {
             int getSum1 = getSum(n1.first);
             int getSum2 = getSum(n2.first);
             if(getSum1!=getSum2) return getSum2>getSum1;
             return n1.first<n2.first;
        };
        sort(afterSorted.begin(),afterSorted.end(),srt);
        int swaps = 0;

        for(int i = 0;i<n;i++) {
            if(afterSorted[i].second==i) continue;
            else {
                swap(afterSorted[i], afterSorted[afterSorted[i].second]);
                swaps++;
                i--; 
            }
        }
        return swaps;
    }
};