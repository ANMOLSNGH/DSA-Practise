class Solution {
public:
    int n;
    unordered_set<string> validSet; 

    void allpossible(int open, int close, int indx, int n_open, int n_close, string &s, string &given) {
        if(indx == n) {
            if(n_open == 0 && n_close == 0 && open == 0 && close == 0) {
                validSet.insert(s);
            }
            return;
        }

        char ch = given[indx];
        
        if(ch == '(') {
            if(open > 0)  {
                s.push_back('(');
                allpossible(open, close, indx+1, n_open+1, n_close, s, given);
                s.pop_back();
                allpossible(open-1, close, indx+1, n_open, n_close, s, given);
            }
            else if(open == 0) { 
                s.push_back('(');
                allpossible(open, close, indx+1, n_open+1, n_close, s, given);
                s.pop_back(); 
            }
        }
        else if(ch == ')') {
            if(close > 0) {
                s.push_back(')');
                if(n_open > 0)
                    allpossible(open, close, indx+1, n_open-1, n_close, s, given);
                else 
                    allpossible(open, close, indx+1, n_open, n_close+1, s, given);
                s.pop_back();
                allpossible(open, close-1, indx+1, n_open, n_close, s, given);
            }
            else if(close == 0) {
                s.push_back(')');
                if(n_open > 0)
                    allpossible(open, close, indx+1, n_open-1, n_close, s, given);
                else 
                    allpossible(open, close, indx+1, n_open, n_close+1, s, given);
                s.pop_back(); 
            }
        }
        else { 
            s.push_back(ch);
            allpossible(open, close, indx+1, n_open, n_close, s, given);
            s.pop_back();
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        
        int open_rem = 0, close_rem = 0;
        for (char ch : s) {
            if (ch == '(') {
                open_rem++;
            } else if (ch == ')') {
                if (open_rem > 0) open_rem--;
                else close_rem++;
            }
        }

        string temp = "";
        allpossible(open_rem, close_rem, 0, 0, 0, temp, s);
        
        return vector<string>(validSet.begin(), validSet.end());
    }
};