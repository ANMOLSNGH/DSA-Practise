class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int d) {
        int n = position.size();
        stack<pair<int,int>>st;
        st.push({speed[n-1],position[n-1]});
        int cnt = 0;
        for(int i = n-2;i>=0;i--) {
            auto [sp,pos] = st.top();
            if(pos-position[i]<=d||speed[i]>sp) {
                st.push({sp,position[i]});
            }
            else {
                while(!st.empty()) {
                    st.pop();
                }
                cnt++;
                st.push({speed[i],position[i]});
            }
        }
        if(!st.empty()) cnt++;

        return cnt;

    }
};