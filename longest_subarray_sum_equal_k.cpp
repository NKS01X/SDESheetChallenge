class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen[0] = 1;
        
        int pre = 0;
        int cnt = 0;
        
        for(int x : nums) {
            pre += x;
            int req = pre - k;
            
            if(seen.find(req) != seen.end()) {
                cnt += seen[req];
            }
            
            seen[pre]++;
        }
        
        return cnt;
    }
};