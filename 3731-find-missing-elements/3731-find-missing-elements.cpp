class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int>st;
        int smallest = INT_MAX;
        int largest = INT_MIN;
        vector<int>ans;
        for(auto num : nums) {
            if(num>largest) largest = num;
            if(num<smallest) smallest = num;
            st.insert(num);
        }
        for(int i = smallest;i<=largest;i++) {
            if(st.find(i)==st.end()) ans.push_back(i);
        }
        return ans;
    }
};