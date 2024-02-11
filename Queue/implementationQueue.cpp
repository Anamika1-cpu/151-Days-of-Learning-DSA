#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int arr[100000];
    int front, rear;

    Queue()
    {
        front = 0;
        rear = 0;
    }
    void push(int x)
    {
        arr[rear] = x;
        rear++;
    }
    int pop()
    {

        if (front == rear)
        {
            // empty
            return -1;
        }
        else
        {
            int temp = arr[front];
            arr[front] = -1;
            front++;
            return temp;
        }
    }
};

int main()
{
    Queue queue;
    queue.push(1);
    return 0;
}