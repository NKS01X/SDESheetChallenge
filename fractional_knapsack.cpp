class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<double,int>> ratio;
        for(int i=0;i<n;i++){
             double sol= (double)val[i]/wt[i];
            ratio.push_back({sol,i});
        }
        
         sort(ratio.begin(), ratio.end(), greater<pair<double, int>>()); 
         double value=0;
         for(int i=0;i<ratio.size();i++){
             int currwt=ratio[i].second;
             if(capacity>=wt[currwt]){
                 value+=val[currwt];
                 capacity-=wt[currwt];
             }
             else{
                 value += ratio[i].first * capacity;
                break;
             }
         }
         return value;
    }
};
