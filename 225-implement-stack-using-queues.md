# 225. IMplement stack using queue

[link](https://leetcode.com/problems/implement-stack-using-queues/)
**Level**: Easy 

**Memory Use**:  7 MB

**Time**: 0 ms

**Explanation**:
- do as it says.

**Space complexity**: $O(1)$
**time complexity**: $O(n.log(k))$, for storing the element, $O(1)$ for getting top element.

```cpp
class MyStack {
    queue<int>container;
    queue<int>temp;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        container.push(x);
    }
    
    int pop() {
        while(container.size() != 1){
            temp.push(container.front());
            container.pop();
        }
        
        
        int val = container.front();
        container.pop();
        
        // temp.push(val);
        
        while(temp.size()){
            container.push(temp.front());
            temp.pop();
        }
        
        return val;
    }
    
    int top() {
        while(container.size() != 1){
            temp.push(container.front());
            container.pop();
        }
        
        int val = container.front();
        container.pop();
        temp.push(val);
        
        while(temp.size()){
            container.push(temp.front());
            temp.pop();
        }
        
        return val;
    }
    
    bool empty() {
        return container.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

```

