class Solution {
public:
    int upperBoundCount(vector<vector<int>> &mat, int rowIndex, int target){
        
        int low = 0;
        int high = mat[0].size() - 1;
        int ansIndex = mat[0].size(); 
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(mat[rowIndex][mid] > target){
                ansIndex = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return ansIndex; 
    }
    
    int median(vector<vector<int>> &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        int medianIndex = (n * m + 1) / 2;
        
        for(int i = 0; i < n; ++i){
            if(mat[i][0] < mini)
                mini = mat[i][0];
            
            if(mat[i][m-1] > maxi)
                maxi = mat[i][m-1];
        }
        
        int low = mini;
        int high = maxi;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low) / 2;
            int count = 0;
            
            for(int i = 0; i < n; ++i){
                count += upperBoundCount(mat, i, mid);
            }
            
            if(count >= medianIndex){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
