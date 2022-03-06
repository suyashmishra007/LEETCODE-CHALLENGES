class Solution {
public:
    int MOD = 1e9 + 7 ;
    int countOrders(int n) {
        // Coding decoded
        vector<long> dp(501,0);
        dp[1] = 1 ;
        dp[2] = 6 ;
        for(int  i=  3 ; i <= n ; i++){
            int oddNo = 2 * i - 1;
            int permutations = oddNo * (oddNo + 1) / 2 ;
            dp[i] = (dp[i-1]* permutations)  % MOD ;
        }
        return (int)dp[n];
    }
};