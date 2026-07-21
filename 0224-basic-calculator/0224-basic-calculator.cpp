class Solution {
public:
    int perform(long long x,long long y , char op) {
        if(op=='+') return x+y;
        else if(op=='-') return x-y;
        else if(op=='*') return x*y;
        else if(op=='/') return x/y;

        return 0;
    }

    int order(char op) {
        if(op=='+'||op=='-') return 1;
        else if(op=='/'||op=='*') return 2;
        return 0;
    }
    int calculate(string s) {
        int n = s.size();
        stack<long long>digits;
        stack<char>st;
        for(int i = 0;i<n;i++) {
            if(s[i]==' ') continue;
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*') {
                //unary opeator 
                if(s[i]=='+'||s[i]=='-') {
                int j = i-1;
                while(j>=0&&s[j]==' ') {
                    j--;
                }
                if(j<0||s[j]=='(') digits.push(0);
            }
                while(!st.empty()&&order(st.top())>=order(s[i])) {
                    long long x = digits.top();
                    digits.pop();
                    long long y = digits.top();
                    digits.pop();
                    long long val = perform(y,x,st.top());
                    digits.push(val);
                    st.pop(); 
                }
                st.push(s[i]);
            }
            else if(s[i]==')') {
                while(!st.empty()&&st.top()!='(') {
                    long long x = digits.top();
                    digits.pop();
                    long long y = digits.top();
                    digits.pop();
                    long long val = perform(y,x,st.top());
                    digits.push(val);
                    st.pop(); 
                }
                if (!st.empty()) st.pop();
            }
          else  if (isdigit(s[i])) {
                long long num = 0; 
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; 
                digits.push(num);
            }
        }
        while(!st.empty()) {
              long long x = digits.top();
              digits.pop();
              long long y = digits.top();
              digits.pop();
              long long val = perform(y,x,st.top());
              digits.push(val);
              st.pop(); 
        }
       return digits.empty() ? 0 : digits.top();
    }
};