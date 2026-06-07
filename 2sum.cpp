class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        unordered_map<int,int> mp;
        for(int i = 0;i < n; ++i) {
            mp[nums[i]] = i;
        }
        for(int i = 0;i < n; ++i) {
            int tar = target - nums[i];
            // cout << tar << endl;
            if(mp.find(tar) != mp.end() && mp[tar] != i) {
                return {i,mp[tar]};
            }
        }
        return {-1,-1};
    }
};