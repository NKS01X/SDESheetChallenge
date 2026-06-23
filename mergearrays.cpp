class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat){
        int k = mat.size();
        
        vector<int> output;
    
        // Min-heap: {value, {array index, element index}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minHeap;
    
        // Push first element of each array
        for (int i = 0; i < k; ++i){
            
            if (!mat[i].empty()){
                minHeap.push({mat[i][0], {i, 0}});
            }
        }
    
        // Merge all elements
        while (!minHeap.empty()){
            
            auto top = minHeap.top();
            minHeap.pop();
    
            int val = top.first;
            int i = top.second.first;
            int j = top.second.second;
    
            output.push_back(val);
    
            // Push next element from same array
            if (j + 1 < mat[i].size()){
                
                minHeap.push({mat[i][j + 1], {i, j + 1}});
            }
        }
    
        return output;
    }
};
