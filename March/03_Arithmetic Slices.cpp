class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        
        if(N <= 1) return 0 ;
        vector<int> dp(N,0);
        int total = 0;
        for(int i = 2 ; i < N ; i++){
            
            int third = nums[i] , second = nums[i-1] , first = nums[i-2];
            
            if(second - first == third - second)  dp[i] = dp[i-1] + 1 ;
            else dp[i] = 0;
            
            total += dp[i];
        }
        
        return total;
    }
};