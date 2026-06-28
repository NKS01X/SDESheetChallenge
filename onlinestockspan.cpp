class StockSpanner {
private:
    stack<pair<int,int>> s;
    int i = 0;
public:
    StockSpanner() {}
    
    int next(int price) {
        while(!s.empty() && s.top().second <= price){
            s.pop();
        }
        
        if(s.empty()){
            s.emplace(i, price);
            ++i;
            return i;
        }
        
        int previous = s.top().first;
        s.emplace(i, price); 
        ++i;
        
        return i - 1 - previous; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
