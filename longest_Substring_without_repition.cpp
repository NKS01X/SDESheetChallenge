class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        std::bitset<128> mask;
        int l = 0;
        int ans = 0;
        int len = 0;
        int n = s.length();
        for(int r = 0;r < n; ++r) {
            int i = s[r];
            if(mask.test(i)) {
                while(s[l] != s[r]) {
                    int j = s[l];
                    mask.reset(j);
                    l++;
                    len--;
                }
                l++;
            }else {
                len++;
                ans = max(ans,len);
                mask.set(i);
            }
        }
        return ans;
    }
};