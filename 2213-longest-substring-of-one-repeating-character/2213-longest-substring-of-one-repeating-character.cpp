class Solution {
public:
    class Node {
        public:
        int pref = 0;
        int suff = 0;
        int maxilen = 0;
        char left = 0;
        char right = 0;
    };

    vector<Node>segt;
    int n;

    Node merge(const Node &l,const Node &r,int leftlen,int rightlen) {
          Node res;

          res.left = l.left;
          res.right = r.right;

          res.pref = l.pref;
          if(l.pref==leftlen&&l.right==r.left) {
              res.pref = l.pref + r.pref;
          }

          res.suff = r.suff;

          if(r.suff==rightlen&&l.right==r.left) {
            res.suff = l.suff + r.suff;
          }

          res.maxilen = max(l.maxilen,r.maxilen);

          if(l.right==r.left) {
            res.maxilen = max(res.maxilen,l.suff+r.pref);
          }
          return res;
    }

    void buildsegt(int i , int l,int r,string &s) {
        if(l==r) {
            segt[i] = {1,1,1,s[l],s[l]};
            return;
        }
        int mid = l + (r - l) / 2;
        buildsegt(2*i+1,l,mid,s);
        buildsegt(2*i+2,mid+1,r,s);
        segt[i] = merge(segt[2*i+1],segt[2*i+2],mid-l+1,r-mid);
    }

    void update(int i,int l,int r,int pos,char ch) {
        if(l==r) {
             segt[i] = {1,1,1,ch,ch};
             return;
        }
        int mid = l + (r-l)/2;

        if(pos<=mid) {
            update(2*i+1,l,mid,pos,ch);
        }
        else {
            update(2*i+2,mid+1,r,pos,ch);
        }

        segt[i] = merge(segt[2*i+1],segt[2*i+2],mid-l+1,r-mid);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
         n = s.size();
         segt.assign(4*n,Node());

        buildsegt(0, 0, n - 1, s);
        int k = queryIndices.size();

        vector<int> result(k);
        for(int i = 0;i<k;i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0,0,n-1,pos,ch);

            result[i] = segt[0].maxilen;

        }
        return result;
        
    }
};