class Solution {
private:
    void getsubsets(int index , vector<int>&path , vector<int> &nums , vector<vector<int>> &ans) {

        if (index == nums.size()) {
            ans.push_back(path);
            return;
        }

        // not  pick
        getsubsets(index + 1, path, nums, ans);
        // pick
        path.push_back(nums[index]);
        getsubsets(index + 1, path, nums, ans);
        path.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> ans ;
        if (nums.size() == 0) return ans ;
        vector<int> path;
        getsubsets(0, path, nums, ans);
        sort(ans.begin(), ans.end());
        return ans ;
    }
};