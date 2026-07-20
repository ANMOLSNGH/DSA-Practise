class Solution {
public:

    int perform(int x,int y,char op) {
        if(op=='+') return x+y;
        else if(op=='-') return x - y;
        else if(op=='*') return x*y;
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int>result;
        bool isnumber = 1;

        for(int i = 0;i<expression.size();i++) {
            if(!isdigit(expression[i]))  {
                isnumber = 0;

                vector<int>left = diffWaysToCompute(expression.substr(0,i));
                vector<int>right = diffWaysToCompute(expression.substr(i+1));

                for(auto x: left) {
                    for(auto y:right) {
                        int val = perform(x,y,expression[i]);
                        result.push_back(val);
                    }
                }
            }
        }
        if(isnumber) result.push_back(stoi(expression));
            return result;
    }
};