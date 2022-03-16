class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int N = popped.size();
        
        int popIndex = 0 ;
        stack<int> stk;
        
        for(int pushele :  pushed){
            stk.push(pushele);
            while(!stk.empty() and  stk.top() == popped[popIndex]){
                popIndex++;
                stk.pop();
            }
        }
        
        return popIndex == N ? 1 : 0 ;
    }
};