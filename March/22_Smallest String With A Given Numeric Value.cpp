class Solution {
public:
    string getSmallestString(int n, int k) {
         
        string ans(n,'a');
        
        // n <= k <= 26 * n
        k = k - n ; // beacuse we use nth length 'a' char
        
        int j = n -1 ;
        
        while(k > 0){
            if(k < 25){
                ans[j] = (char)('a' + k);
                k = 0 ; 
            }else{
                ans[j] = 'z';
                k = k - 25 ;
            }
            j--;
        }
        
        return ans;
    }
};