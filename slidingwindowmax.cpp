class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();

        for(int r = 0, l = 0; r < n; ++r) {
            while(!dq.empty() && nums[dq.back()] < nums[r])
                dq.pop_back();

            dq.push_back(r);

            if(dq.front() < l)
                dq.pop_front();

            if(r - l + 1 >= k) {
                ans.push_back(nums[dq.front()]);
                l++;
            }
        }
        return ans;
    }
};

