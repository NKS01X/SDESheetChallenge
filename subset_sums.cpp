class Solution {
  public:
    vector<int> result;
    void solve(vector<int>& arr, int idx,int sum) {
        if (idx == arr.size()){
            result.push_back(sum);return;
        }
        sum+=arr[idx];
        solve(arr, idx + 1,sum);
        sum-=arr[idx];
        solve(arr, idx + 1,sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        solve(arr, 0, 0);
        return result;
    }
};
