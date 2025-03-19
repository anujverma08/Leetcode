#include <queue>

class MyStack {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        queue1.push(x);
        while (!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }
    }
    
    int pop() {
        int val = queue1.front();
        queue1.pop();
        return val;
    }
    
    int top() {
        return queue1.front();
    }
    
    bool empty() {
        return queue1.empty();
    }
};
