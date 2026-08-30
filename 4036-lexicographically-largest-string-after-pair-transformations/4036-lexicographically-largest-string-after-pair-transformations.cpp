class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        for(int x:nums){
            string temp="";
            char ch='a';
            while(x>=1){
                if(x%2!=0){
                    temp+=ch;
              
                }
                x/=2;
                ch++;
                if(ch=='z')break;
            }
            while(x--){
                 temp+='z';                
            }
            reverse(temp.begin(),temp.end());
           ans.push_back(temp);
        }
        return ans;
    }
};