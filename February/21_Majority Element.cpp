class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int value = nums[0] , cnt = 1;
        for (int i = 1 ; i < nums.size(); i++) {
            if (nums[i] == value) cnt++;
            else {
                cnt -= 1;
                if (cnt == 0) {
                    value = nums[i];
                    cnt = 1 ;
                }
            }
        }

        return value;
    }
};