class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str_num;

        for(auto num : nums) {
            str_num.push_back(to_string(num));
        }

        sort(str_num.begin(),str_num.end(),[&](const string &s1 , const string &s2) {
            return s1 + s2>s2 + s1;
        });

        if(str_num[0]=="0") return "0";

        string result = "";
        for (const string &s : str_num) {
            result += s;
        }
        
        return result;
    }
};