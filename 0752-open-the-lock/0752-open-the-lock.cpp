class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        unordered_set<string>mpp(deadends.begin(),deadends.end());

        queue<pair<string,int>>pq;
        if(mpp.find("0000")!=mpp.end()) return -1;
        pq.push({"0000",0});
        mpp.insert("0000");

        while(!pq.empty()) {
            string curr = pq.front().first;
            int moves = pq.front().second;
            pq.pop();
            if(curr==target) return moves;

            for(int i = 0;i<4;i++) {
                for(auto possible_move : {1,-1}) {
                    int newdigi = (curr[i]-'0' + possible_move + 10)%10;
                    string newstr = curr;
                    newstr[i] = (newdigi+'0');


                    if(mpp.find(newstr)==mpp.end()) {
                        mpp.insert(newstr);
                        pq.push({newstr,moves+1});
                    }
                }
            }
        }
        return -1;
    }
};