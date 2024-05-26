#include <bits/stdc++.h>
using namespace std;

queue<int> reverseKelements(queue<int> q, int k)
{
    // 1. Push first k the elements in stack and pop from queue.
    stack<int> s;
    queue<int> ansq;
    int sizeOfQueue = q.size();
    for (int i = 0; i < k; i++)
    {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }
    // 2. Push all k elements from stack to queue
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        ansq.push(temp);
    }
    // 3. Pop first sizeOfQueue(n)-k elements from
    // start of queue & push in to end of the queue.
    for (int i = 0; i < sizeOfQueue - k; i++)
    {
        int temp = q.front();
        q.pop();
        ansq.push(temp);
    }
    return ansq;
}
void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    int k = 2;
    cout << "Original Queue:" << endl;
    printQueue(q);
    queue<int> ans = reverseKelements(q, k);
    cout << "Queue after reversing k(" << k << ") elements:" << endl;
    printQueue(ans);
    return 0;
}