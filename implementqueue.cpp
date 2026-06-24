class myQueue {
    vector<int> q;
    int top;
    int curr;
    int sz;
    int count;
    
public:
    myQueue(int n) {
        sz = n;
        q.resize(n);
        top = 0;
        curr = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == sz; 
    }

    void enqueue(int x) {
        if (isFull()) return;
        q[curr] = x;
        curr = (curr + 1) % sz;
        count++;
    }

    void dequeue() {
        if (isEmpty()) return;
        top = (top + 1) % sz;
        count--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return q[top];
    }

    int getRear() {
        if (isEmpty()) return -1;
        int rearIndex = (curr - 1 + sz) % sz; 
        return q[rearIndex];
    }
};
