class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int MAX = 10002;
        vector<int> freq(MAX, 0) , dp(MAX, 0);

        for (int ele : nums) {
            freq[ele]++;
        }

        dp[0] = 0 ;
        dp[1] = 1 * freq[1];

        for (int i = 2 ; i < MAX ; i++) {
            int notPicked = dp[i - 1];
            int picked = dp[i - 2] + (i * freq[i]);
            dp[i] = max(notPicked, picked);
        }

        return dp[MAX-1];
    }
};