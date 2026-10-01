class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i =0;
        int n = s.size();
        
      for(int i = 0;i<n;i++) {
            if(!st.empty()&&(s[i]==')'&&st.top()=='('||s[i]=='}'&&st.top()=='{'||s[i]==']'&&st.top()=='[')) {
                st.pop();
            }
            else {
            st.push(s[i]);
            }
        }
    
        bool ans = st.empty()? true : false;
        return ans;
    }
};