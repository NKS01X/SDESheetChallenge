class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int r = nums[0];
        for(auto &x: nums) {
            if(cnt == 0) {
                r = x;
                cnt = 1;
            }
            else if(x == r) cnt++;
            else cnt--;
        }
        return r; 
    }
};