// https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

            int count = 0 ; 
            unordered_map<int,int> totalSum ;

            for(auto n1 : nums1){
                for(auto n2 : nums2){
                    totalSum[n1+n2]++;
                }
            }


            for(auto n3 : nums3){
                for(auto n4 : nums4){
                    if(totalSum.find(0 - (n3+n4)) != totalSum.end()){
                        count += totalSum[0-(n3+n4)];
                    }
                }
            }
            return count;
    }
};