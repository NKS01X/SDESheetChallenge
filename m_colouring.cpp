class Solution {
    vector<int> col;

    bool solve(vector<int> g[], int m, int v, int node) {
        if (node == v) return true;

        int mask = 0; 
        
        for (auto &nei : g[node]) {
            if (col[nei] != -1) {
                mask |= (1 << col[nei]); 
            }
        }

        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1) continue;

            col[node] = i;

            if (solve(g, m, v, node + 1)) return true;

            col[node] = -1;
        }

        return false;
    }

public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int> g[v];
        for (auto &x : edges) {
            int u = x[0], w = x[1];
            g[u].push_back(w);
            g[w].push_back(u); 
        }
        
        col.assign(v, -1); 
        
        return solve(g, m, v, 0);
    }
};
