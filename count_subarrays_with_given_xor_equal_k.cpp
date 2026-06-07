class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        unordered_map<int,int> seen;
        int pre = 0;
        seen[pre] = 1;
        
        int ans = 0;
        for(auto &x: nums) {
            pre ^= x;
            int req = pre ^ k;
            ans += seen[req];
            seen[pre]++;
        }
        return ans;
    }
};