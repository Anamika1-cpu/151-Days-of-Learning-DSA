#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> &q)
{
    stack<int> s;

    // one by one insert element in stack from queue
    while (!q.empty())
    {
        int front_elememt = q.front();
        q.pop();
        s.push(front_elememt); // insert
    }

    // add element in queue one by one from stack
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

void printq(queue<int> &q)
{
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        cout << ele << " ";
    }
    cout << endl;
}
int main()
{
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    qu.push(60);
    queue<int> originalQueue = qu;
    cout << "Queue before reversing " << endl;
    printq(originalQueue);
    cout << "Queue after reversing " << endl;
    queue<int> revq = reverseQueue(qu);
    printq(revq);
    return 0;
}