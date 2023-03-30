#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class MinStack {
private:

    stack<int> s1; // be used as normal stack
    stack<int> s2; // to store current min

public:
    MinStack() {}
    
    void push(int val) {
        // if s2 is empty or val is smaller or "equal" than the current smallest number
        // push val to s2
        // notice that if val is "equal" to the current smallest number, we have to push it to stack!
        if (s2.empty() == true || val <= getMin()){
            s2.push(val);
        }

        // push val to s1
        s1.push(val);
    }
    
    void pop() {
        if (s1.top() == getMin()){
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

int main(){

    /*
    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output
    [null,null,null,null,-3,null,0,-2]
    */

    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;

    return 0;
}