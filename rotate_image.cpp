class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        //simple transpose + swap 
        int n = mat.size(); 
        int m = mat[0].size();
        
        int i = 0, j = m - 1;
        while(i <= j) {
            swap(mat[i],mat[j]);
            ++i;--j;
        }

        for(int i = 0;i < n; ++i) {
            for(int j = i + 1;j < m; ++j) {
                swap(mat[i][j],mat[j][i]);
            }
        }
        
    }
};