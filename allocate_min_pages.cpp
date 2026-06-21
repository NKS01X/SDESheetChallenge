class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        
        
        
        //Agar students > books → answer always -1
        if(k > arr.size()) return -1;
        
        
        //find max element
        int ans = INT_MIN, n=arr.size(),sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>ans)
            ans = arr[i];
            sum += arr[i];
        }
        
        int st = ans, end = sum,result=-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            
            int page = 0, count=1;
            for(int i=0;i<n;i++){
                page += arr[i];
                
                if(page>mid)
                {
                    count++;
                    page = arr[i];
                }
            }
            
            
            if(count<=k){
                result = mid;
                end = mid-1;
            }
            else st = mid+1;
        }
        
        return result;
    }
};
