/**
 * @param {string} s
 * @return {number}
 */
var scoreOfParentheses = function(s) {
    var depth = 0;
    var score = 0;
    for(var i = 0;i<s.length;i++) {
        if(s[i]=='(') depth++;
        else {
            depth--;
            if(s[i-1]=='(') {
                score += (1<<depth);
            }
        }
    }
        return score;
    };
