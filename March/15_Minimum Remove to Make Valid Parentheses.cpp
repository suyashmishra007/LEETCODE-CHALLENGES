class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int N = s.size();
        char inValid = '#';
        
        stack<int> stk ;
        
        for(int  i = 0 ; i < N ; i++){
            char ch = s[i];
            if(ch == '('){
                stk.push(i);
            }else if(ch == ')'){
                if(stk.size() == 0){
                    s[i] = inValid;
                }else{
                    stk.pop();
                }
            }
        }
        
        while(!stk.empty()){
            s[stk.top()] = inValid;
            stk.pop();
        }
        
        string ans = "";
        
        for(auto ch : s){
            if(ch == inValid)continue;
            ans += ch;
        }
        
        return ans;
    }
};