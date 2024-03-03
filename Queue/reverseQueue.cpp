#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;

    // one by one insert element in stack from queue
    while (!q.empty())
    {
        int fron_elememt = q.front();
        q.pop();
        s.push(fron_elememt); // insert
    }

    // add element in queue one by one from stack
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
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
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout << "Queue after reversing " << endl;
    reverseQueue(q);
    printq(q);
    return 0;
}