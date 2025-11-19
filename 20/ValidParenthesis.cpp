class Solution {
public:
    bool isValid(string s) {
        std::stack<char> check;
        for (char c : s){
            if (c == '(' || c == '{' || c == '['){
                check.push(c);
            }else if (!check.empty() && check.top() == leftof(c)){
                check.pop();
            }else{
                return false;
            }
        }
        return check.empty();
    }
    char leftof(char c){
        if (c == ')') return '(';
        if (c == '}') return '{';
        else return '[';
    }
};