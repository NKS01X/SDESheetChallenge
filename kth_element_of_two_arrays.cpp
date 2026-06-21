class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int len1=a.size();
        int len2=b.size();
        int index=0;
        int i=0,j=0;
        while(i<len1 && j<len2){
            if(a[i]<=b[j]){
                index++;
                if(k==index) return a[i];
                i++;
            }
            else{
                index++;
                if(k==index) return b[j];
                j++;
            }
        }
        if(i==len1){
            for(int l=j;l<len2;l++){
                index++;
                if(k==index) return b[l];
            }
        }
        else{
            for(int l=i;l<len1;l++){
                index++;
                if(k==index) return a[l];
            }
        }
    }
};
