#include <iostream>
using namespace std;

/*
push 
pop
top
ısEmpty

push :
    if stack is full
        return
    else 
        increment top
        stack[top] = value
pop :
    if stack is empty
        return 
    else
        store the value of top 
        decrement the top
        return value
top :
    return stack[top]                        
*/

# define MAX 1000
class Stack
{
    int top;
public:
    int a[MAX];
    Stack()
    {
        top = -1;
    }
    bool push(int i);
    int pop();
    int peek();
    bool isEmpty();
};

void Stack::push(int d)
{
    if(top >= (MAX -1))
    {
        cout << "Stack overflow" << endl;
        return false;
    } else {
        a[++top] = d;
        cout << d << endl;
        return true;
    }
}

int Stack::pop()
{
    if(top < 0)
    {
        cout << "Stack underflow" << endl;
        return 0;
    } else {
       int x = a[--top];
       return x;
    }
}

int Stack::peek()
{
    if(top < 0)
    {
        cout << "Stack is empty" << endl;
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
}