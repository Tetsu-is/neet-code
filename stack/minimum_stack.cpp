#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class MinStack
{
private:
    std::stack<int> stack;
    std::stack<int> minStack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        stack.push(val);
        val = std::min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }

    void pop()
    {
        stack.pop();
        minStack.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(1); // 1/1
    minStack.push(2); // 1,2/1,1
    minStack.push(0); // 1,2,0/1,1,0
    minStack.getMin(); // return 0
    minStack.pop(); // 1,2/1,1
    minStack.top();    // return 2
    minStack.getMin(); // return 1
    return 0;
}