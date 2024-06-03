#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
    int size, front, rear, *arr;

public:
    MyCircularDeque(int k)
    {
        size = k;
        front = rear = -1;
        arr = new int[size];
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false; // overflow
        else if (isEmpty())
        { // empty
            front = rear = 0;
            arr[front] = value;
        }
        else if (front == 0)
        { // circular
            front = size - 1;
            arr[front] = value;
        }
        else
        { // normal case
            front--;
            arr[front] = value;
        }
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false; // overflow
        else if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = value;
        }
        else if (rear == size - 1)
        { // circular
            rear = 0;
            arr[rear] = value;
        }
        else
        { // normal case
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false; // underflow
        else if (front == rear)
        { // single element
            front = rear = -1;
        }
        else if (front == size - 1)
        { // circular
            front = 0;
        }
        else
        { // normal case
            front++;
        }
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false; // underflow
        else if (front == rear)
        { // single element
            front = rear = -1;
        }
        else if (rear == 0)
        { // circular
            rear = size - 1;
        }
        else
        { // normal case
            rear--;
        }
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }
};
int main()
{
    MyCircularDeque deque(5);

    cout << "Insert 1 at rear: " << (deque.insertLast(1) ? "Success" : "Fail") << endl;
    cout << "Insert 2 at rear: " << (deque.insertLast(2) ? "Success" : "Fail") << endl;
    cout << "Insert 3 at rear: " << (deque.insertLast(3) ? "Success" : "Fail") << endl;
    cout << "Insert 4 at front: " << (deque.insertFront(4) ? "Success" : "Fail") << endl;
    cout << "Insert 5 at front: " << (deque.insertFront(5) ? "Success" : "Fail") << endl;
    cout << "Insert 6 at front (should fail): " << (deque.insertFront(6) ? "Success" : "Fail") << endl;

    cout << "Front item: " << deque.getFront() << endl;
    cout << "Rear item: " << deque.getRear() << endl;

    cout << "Delete front: " << (deque.deleteFront() ? "Success" : "Fail") << endl;
    cout << "Delete rear: " << (deque.deleteLast() ? "Success" : "Fail") << endl;

    cout << "Front item: " << deque.getFront() << endl;
    cout << "Rear item: " << deque.getRear() << endl;

    return 0;
}
