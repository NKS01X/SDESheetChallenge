class maxHeap {
  private:
    // Initialize your data members
    vector<int> arr;

  public:

    void push(int x) {
        // Insert x into the heap
        arr.push_back(x);
        sort(arr.begin(),arr.end());
        
    }

    void pop() {
        // Remove the top (maximum) element
        arr.pop_back();
    }

    int peek() {
        if(arr.size()==0){
            return -1;
        }
        return arr.back();
        // Return the top element or -1 if empty
    }

    int size() {
        return arr.size();
        // Return the number of elements in the heap
    }
};
