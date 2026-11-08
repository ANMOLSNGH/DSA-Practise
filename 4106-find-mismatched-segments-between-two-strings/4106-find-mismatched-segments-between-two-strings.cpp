class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;
        int i = 0 , j = 0;
        int n = s1.size();
        string a = "";
        string b = "";
        vector<string>res;
        while(i<n&&j<n) {
            if(s1[i]!=s2[j]) {
                a += s1[i];
                b += s2[j];
            }
            else {
                if(a!=""&&b!="") {
                    res.push_back(a);
                    res.push_back(b);

                    ans.push_back(res);
                }

                res.clear();
                a.clear();
                b.clear();
            }
            i++,j++;
        }
        if(a!=""&&b!="") {
            res.push_back(a);
            res.push_back(b);

            ans.push_back(res);
        }
        return ans;
    }
};