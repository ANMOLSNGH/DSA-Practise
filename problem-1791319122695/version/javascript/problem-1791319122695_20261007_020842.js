// Last updated: 10/7/2026, 2:08:42 AM
1/**
2 * @param {string} s
3 * @return {number}
4 */
5var scoreOfParentheses = function(s) {
6    var depth = 0;
7    var score = 0;
8    for(var i = 0;i<s.length;i++) {
9        if(s[i]=='(') depth++;
10        else {
11            depth--;
12            if(s[i-1]=='(') {
13                score += (1<<depth);
14            }
15        }
16    }
17        return score;
18    };
19