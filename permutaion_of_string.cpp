class Solution {
    vector<vector<int>> v;
    void fn(vector<int>& nums,int mask,vector<int> temp) {
        if(temp.size() == nums.size()) {
            v.push_back(temp);
            return;
        }
        for(int i = 0;i < nums.size(); ++i) {
            if(!(mask>>i&1)) {
                temp.push_back(nums[i]);
                fn(nums,mask|(1<<i),temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        fn(nums,0,temp);
        return v;
    }
};
