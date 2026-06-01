class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0],curr_sum = 0;
        for(int i = 0;i < n; ++i) {
            curr_sum = max(nums[i],curr_sum + nums[i]);
            sum = max(sum,curr_sum);
        }   
        return sum;
    }
};