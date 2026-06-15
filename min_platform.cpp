class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        if (n == 0) return 0;
        
        vector<pair<int, int>> trains(n);
        for(int i = 0; i < n; ++i) {
            trains[i] = {arr[i], dep[i]};
        }
        sort(trains.begin(), trains.end());
        
        multiset<int> s;
        s.insert(trains[0].second);
        
        for(int i = 1; i < n; ++i) {
            int x = trains[i].first; 
            
            auto it = s.lower_bound(x);
            
            if(it == s.begin()) {
                s.insert(trains[i].second);
            } 
            else {
                it--;
                s.erase(it); 
                s.insert(trains[i].second); 
            }
        }
        
        return s.size();
    }
};
