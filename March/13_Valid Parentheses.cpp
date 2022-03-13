class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        
        for(auto &ch : s){
            if(ch == '(' or ch == '{' or ch == '[') stk.push(ch);
            else{
                if(stk.empty()) return false;
                
                if(ch == ')'){
                    if(stk.top() != '('){
                        return false;
                    }else{
                        stk.pop();
                    }
                }else if(ch == '}'){
                    if(stk.top() != '{' ){
                        return false;
                    }else{
                        stk.pop();
                    }
                }else if(ch == ']' ){
                    if(stk.top() != '['){
                        return false;
                    }else{
                        stk.pop();
                    }
                }
            }
        }
        
        return stk.empty();
    }
};