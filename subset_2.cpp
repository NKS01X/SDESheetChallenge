class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        
        int totalSubsets = 1 << n;
        vector<vector<int>> res;
        
        for (int i = 0; i < totalSubsets; ++i) {
            vector<int> ans;
            bool isDuplicate = false;
            
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    if (j > 0 && nums[j] == nums[j - 1] && !((i >> (j - 1)) & 1)) {
                        isDuplicate = true;
                        break;
                    }
                    ans.push_back(nums[j]);
                }
            }
            
            if (!isDuplicate) {
                res.push_back(ans);
            }
        }
        return res;
    }
};
