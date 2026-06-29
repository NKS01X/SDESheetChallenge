class Solution {
public:
    string reverseWords(string& s) {
        int n = s.length();
        string ans = "";
        int fl = 0;    
        int first = 0; 
        string temp = "";
        
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == ' ') {
                if (fl) { 
                    reverse(temp.begin(), temp.end());
                    
                    if (first) {
                        ans += ' '; 
                    }
                    
                    ans += temp;
                    temp = "";
                    fl = 0;      
                    first = 1;   
                }
            } else {
                fl = 1; 
                temp += s[i];
            }
        }
        
        if (fl) {
            reverse(temp.begin(), temp.end());
            if (first) {
                ans += ' ';
            }
            ans += temp;
        }
        
        return ans; 
    }
};
