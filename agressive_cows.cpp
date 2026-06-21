bool isPossible(vector<int> &arr, int k, int m){
        int cow = 1;
        int lastPos = arr[0];

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - lastPos >= m){
                cow++;
                lastPos = arr[i];
            }

            if(cow >= k)
                return true;
        }
        return false;
    }


class Solution {
  public:
    int aggressiveCows(vector<int> &arr, int k) {
   
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int s = 1;
        int e = arr[n-1] - arr[0];
        int ans = 0;

        while(s <= e){
            int m = (s + e) / 2;

            if(isPossible(arr, k, m)){
                ans = m;
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }
        return ans;
    }
};
