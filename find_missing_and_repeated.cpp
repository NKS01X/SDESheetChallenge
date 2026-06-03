class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0LL;
        long long sumsq = 0LL;
        
        for (auto &row : grid) {
            for (int val : row) {
                sum += val;
                sumsq += (long long)val * val;
            }
        }
        
        long long n = grid.size();
        long long m = n * n;
        
        long long s = m * (m + 1) / 2;
        long long ssq = m * (m + 1) * (2 * m + 1) / 6;

        long long sumdiff = sum - s;      
        long long sumsqdiff = sumsq - ssq; 
        
        long long apb = sumsqdiff / sumdiff; 
        long long amb = sumdiff;             

        int a = (apb + amb) / 2;
        int b = (apb - amb) / 2;
        
        return {a, b};
    }
};