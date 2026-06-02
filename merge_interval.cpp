class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intL) {
        sort(intL.begin(),intL.end(),
        [](const vector<int> &a,const vector<int> &b){
            int stA = a[0], enA = a[1];
            int stB = b[0], enB = b[1];
            if(stA == stB) {
                return enA < enB; 
            }else {
                return stA < stB;
            }
        });    
        // for(auto &x: intL) {
        //     cout << x[0] << " " << x[1] << endl; 
        // }
        vector<vector<int>> pairs;
        pairs.push_back(intL[0]);
        vector<int> *prev = &pairs.back();
        
        int n = intL.size();
        for(int i = 1;i < n; ++i) {
            int stB = intL[i][0], enB = intL[i][1];
            int stA = (*prev)[0], enA = (*prev)[1];
            // cout << (*prev)[0] << " " <<(*prev)[1] << endl;
            if(stB <= enA) {
                // cout << enB << endl;
                (*prev)[1] = max(enB,enA);
            }else {
                pairs.push_back(intL[i]);
                prev = &pairs.back();
            }    
        }
        return pairs;
    }
};