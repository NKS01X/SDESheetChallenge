class Solution {
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }

public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> v(n);
        
        int max_deadline = 0;
        for(int i = 0; i < n; ++i) {
            v[i] = {deadline[i], profit[i]};
            max_deadline = max(max_deadline, deadline[i]); 
        }
        
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second; 
        });
        
        vector<int> parent(max_deadline + 1);
        for (int i = 0; i <= max_deadline; ++i) {
            parent[i] = i;
        }
        
        int tot_jobs = 0;
        int tot_profit = 0;
        
        for(int i = 0; i < n; ++i) {
            int available_slot = find(v[i].first, parent);
            
            if (available_slot > 0) {
                tot_jobs++;
                tot_profit += v[i].second;
                parent[available_slot] = available_slot - 1;
            }
        } 
        
        return {tot_jobs, tot_profit};
    }
};
