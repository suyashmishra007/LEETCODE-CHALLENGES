class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		    
        int N = nums.size();
        int maxLen = 0;

		unordered_map<int, int> ump;

		int sum = 0 ;
		ump[sum] = -1;

		for (int i = 0; i < N ; i++) {

			// Treat 0 as -1 , and 1 as 1
			sum += (nums[i] == 0) ? -1 : 1;

			if (ump.find(sum) != ump.end()) {
				maxLen = max(maxLen, i - ump[sum]);
			} else {
				ump[sum] = i ;
			}
		}

		return maxLen;
	}
};