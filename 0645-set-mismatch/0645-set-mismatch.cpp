class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
      int n = arr.size();
        
        unsigned int xori = 0;
        
        for(int i = 0;i<n;i++) {
            xori ^= arr[i];
            xori ^= (i+1);
        }
        
        unsigned set_bit = xori &(-xori);
        
        
        int num1 = 0;
        int num2 = 0;
        for(int i = 0;i<n;i++) {
            if(arr[i]&set_bit) num1 ^= arr[i];
            else num2 ^= arr[i];
        }
        
        for(int i = 1;i<=n;i++) {
            if(i&set_bit) num1 ^= i;
            else num2 ^= i;
        }
        
        bool found = false;
        
        for(auto num : arr) {
            if(num==num1) {
                found = true;
                break;
            }
        }
        
        if(found) return {num1,num2};
        return {num2,num1};
    }
};