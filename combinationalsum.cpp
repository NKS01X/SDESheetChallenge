class Solution {
    void fn(vector<int>& nums, int left, int idx, vector<int>& path, vector<vector<int>>& ans) {
        if (left == 0) {
            ans.push_back(path);
            return;
        }
        if (idx == nums.size() || left < 0) return;

        path.push_back(nums[idx]);
        fn(nums, left - nums[idx], idx, path, ans);
        path.pop_back();
        fn(nums, left, idx + 1, path, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        fn(candidates, target, 0, path, ans);
        return ans;
    }
};
