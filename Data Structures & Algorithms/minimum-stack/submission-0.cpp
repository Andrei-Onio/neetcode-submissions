class MinStack {
public:
    stack<int> stk, mini;
    MinStack() {

    }

    void push(int val) {
        if(stk.empty() || val <= mini.top()) {
            mini.push(val);
        }
        stk.push(val);
    }

    void pop() {
        if(stk.top() == mini.top()) {
            mini.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mini.top();
    }
};