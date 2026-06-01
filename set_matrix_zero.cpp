class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool isfirstrow = false;
        bool isfirstcol = false;

        for(int i = 0;i < n; ++i) 
            isfirstcol |= !matrix[i][0];
        for(int j = 0;j < m; ++j) 
            isfirstrow |= !matrix[0][j];

        for(int i = 0;i < n; ++i) {
            for(int j = 0;j < m; ++j) {
                if(!matrix[i][j]) {
                    matrix[i][0] = 0; 
                    matrix[0][j] = 0;
                }
            }
        }

        // for(int i = 0;i < n; ++i) {
        //     for(int j = 0;j < m; ++j) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 1;i < n; ++i) {
            if(matrix[i][0] == 0) {
                for(int j = 1;j < m; ++j) 
                    matrix[i][j] = 0;
            } 
        }
        for(int i = 1;i < m; ++i) {
            if(matrix[0][i] == 0) {
                // cout << matrix[0][i] << "found" << endl;
                for(int j = 1;j < n; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        // cout << isfirstrow << endl;
        if(isfirstcol) {
            for(int i = 0;i < n; ++i) 
                matrix[i][0] = 0;
        }
        if(isfirstrow) {
            for(int j = 0;j < m; ++j) 
                matrix[0][j] = 0;
            
        }
    }
};