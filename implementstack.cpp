class myStack {
    vector<int> s;
    int idx;
    int sz;
public:
    myStack(int n) {
        // Define Data Structures
        s.resize(n);
        idx = 0;
        sz = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        if(idx == 0) return true;
        return false;
    }

    bool isFull() {
        // check if the stack is full
        if(idx == sz) return true;
        return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()) return;
        s[idx++] = x; 
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()) return;
        idx--;
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty()) return -1;
        return s[idx - 1];
    }
};
class MyQueue {
public:
    stack<int> inStack, outStack;

    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        peek();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MyStack {
public:
    queue<int> que;

    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
        int n = que.size(); 

        for(int i=0; i<n-1; i++){
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int result = que.front();
        que.pop();

        return result;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};
