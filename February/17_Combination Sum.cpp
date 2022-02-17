class Solution {
private:
	void combination(int index , int target , vector<int> &ans , int &ansSum,
	                 vector<vector<int>> &outputArr, vector<int> &candidates) {

		// add the vector into the output_vector
		if (ansSum == target) {
			outputArr.push_back(ans);
			return;
		}
		if (index == candidates.size()) {
			return ;
		}

		// pick
		if (ansSum < target) {
			ansSum += candidates[index];
			ans.push_back(candidates[index]);
			combination(index, target, ans, ansSum, outputArr, candidates);
			ansSum -= candidates[index];
			ans.pop_back();
		}
		// notpick
		combination(index + 1, target, ans, ansSum, outputArr, candidates);
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> outputArr ;
		vector<int> ans ;
		int ansSum = 0 ;
		combination(0, target, ans, ansSum, outputArr, candidates);
		return outputArr ;
	}
};