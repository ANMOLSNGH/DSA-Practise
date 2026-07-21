class Solution {
public:
    string minimizeResult(string expression) {
        int n = expression.size();
        string ans = "";
        int mini = INT_MAX;
        int left_indx = 0;
        int right_indx = 0;
        int indx = 0;
        
        // Find the '+' sign
        for(int i = 0; i < n; i++) {
            if(expression[i] == '+') {
                indx = i;
                break;
            }
        }
        
        for(int i = indx + 1; i < n; i++) {
            long long right_num1 = 0;
            long long left_num1 = 0;
            
            // left_num1: inside right parenthesis
            for(int j = indx + 1; j <= i; j++)
                left_num1  = left_num1 * 10 + (expression[j] - '0');
                
            // right_num1: outside right parenthesis
            for(int j = i + 1; j < n; j++) 
                right_num1  = right_num1 * 10 + (expression[j] - '0');
            
            for(int j = indx - 1; j >= 0; j--) {
                long long left_num2 = 0;
                long long right_num2 = 0;
                
                // left_num2: outside left parenthesis
                for(int k = 0; k < j; k++) 
                    left_num2 = left_num2 * 10 + (expression[k] - '0');
                
                // right_num2: inside left parenthesis
                for(int k = j; k < indx; k++) 
                    right_num2 = right_num2 * 10 + (expression[k] - '0');

                // FIX 1: If there is no number on the outside, multiply by 1, not 0
                long long mult_left = (j == 0) ? 1 : left_num2;
                long long mult_right = (i == n - 1) ? 1 : right_num1;

                long long possible_ans = (right_num2 + left_num1) * mult_left * mult_right;

                // FIX 2: Save the correct bounds for the parentheses
                if(possible_ans < mini) {
                    mini = possible_ans;
                    left_indx = j;      // '(' goes just before j
                    right_indx = i;     // ')' goes just after i
                }
            }
        }
        
        // FIX 3: Construct the final answer string using the saved best indices
        for(int k = 0; k < left_indx; k++) 
            ans += expression[k];
            
        ans += '(';
        
        for(int k = left_indx; k <= right_indx; k++) 
            ans += expression[k];
            
        ans += ')';
        
        for(int k = right_indx + 1; k < n; k++) 
            ans += expression[k];
            
        return ans;
    }
};