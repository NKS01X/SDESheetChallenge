class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        if (min_heap.size() == max_heap.size() || 
            min_heap.size() == max_heap.size() + 1 || 
            max_heap.size() == min_heap.size() + 1) {
            return; 
        }

        if (min_heap.size() > max_heap.size()) {
            int e = min_heap.top(); 
            min_heap.pop();
            max_heap.push(e);
        } else {
            int e = max_heap.top(); 
            max_heap.pop();
            min_heap.push(e);
        }   
    }
    
    double findMedian() {
        if (min_heap.size() == max_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0; 
        }
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        }
        return min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
