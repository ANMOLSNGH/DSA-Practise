// Last updated: 8/30/2026, 3:30:48 PM
1class Solution {
2public:
3    vector<string> largestString(vector<int>& nums) {
4        vector<string>ans;
5        for(int x:nums){
6            string temp="";
7            char ch='a';
8            while(x>=1){
9                if(x%2!=0){
10                    temp+=ch;
11              
12                }
13                x/=2;
14                ch++;
15                if(ch=='z')break;
16            }
17            while(x--){
18                 temp+='z';                
19            }
20            reverse(temp.begin(),temp.end());
21           ans.push_back(temp);
22        }
23        return ans;
24    }
25};