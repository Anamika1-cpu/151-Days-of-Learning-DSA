#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        else
        {
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    int getSize()
    {
        return top + 1;
    }
    void printStack()
    {
        cout << "Top:  " << top << endl;
        cout << "Top element: " << getTop() << endl;
        cout << "Stack: ";
        for (int i = 0; i < getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
    }
};

int main()
{
    Stack st(8);
    st.push(10);
    st.push(20);
    st.printStack();

    cout << endl
         << "Top elemet: " << st.getTop() << endl;
    cout << endl
         << "Size of stack: " << st.getSize() << endl;

    st.pop();
    st.pop();
    if (st.isEmpty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }
    return 0;
}