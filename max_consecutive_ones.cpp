class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int curr = 0;
        int n = nums.size();
        nums.push_back(0);
        for(int i = 0;i <= n; ++i) {
            if(!nums[i]) {
                sum = max(sum,curr);
                curr = 0;
                continue;
            }
            curr++;
        }
        return sum;
    }
};
