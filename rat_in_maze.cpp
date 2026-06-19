class Solution {
    vector<string> ans;
    
    void fn(int n, int x, int y, string &s, vector<vector<int>> &maze) {
        if (x == n - 1 && y == n - 1) {
            ans.push_back(s);
            return;
        }
        
        maze[x][y] = 0;
        
        if (x + 1 < n && maze[x + 1][y] == 1) {
            s.push_back('D');
            fn(n, x + 1, y, s, maze);
            s.pop_back();
        }
        
        if (y - 1 >= 0 && maze[x][y - 1] == 1) {
            s.push_back('L');
            fn(n, x, y - 1, s, maze);
            s.pop_back();
        }
        
        if (y + 1 < n && maze[x][y + 1] == 1) {
            s.push_back('R');
            fn(n, x, y + 1, s, maze);
            s.pop_back();
        }
        
        if (x - 1 >= 0 && maze[x - 1][y] == 1) {
            s.push_back('U');
            fn(n, x - 1, y, s, maze);
            s.pop_back();
        }
        
        maze[x][y] = 1;
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        
        if (n == 0 || maze[0][0] == 0 || maze[n-1][n-1] == 0) {
            return ans;
        }
        
        string s = "";
        fn(n, 0, 0, s, maze);
        return ans;
    }
};
