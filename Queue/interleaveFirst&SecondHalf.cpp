#include <bits/stdc++.h>
using namespace std;

queue<int> interLeaveQueue(queue<int> &q)
{
    // 1. Push first half of original queue in second queue
    queue<int> secondq;
    int size = q.size();
    for (int i = 0; i < size / 2; i++)
    {
        int temp = q.front();
        q.pop();
        secondq.push(temp);
    }
    // 2. Merge both the halves into original queue
    for (int i = 0; i < size / 2; i++)
    {
        int temp = secondq.front();
        secondq.pop();
        q.push(temp);
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    return q;
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
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Original Queue:" << endl;
    printQueue(q);
    queue<int> ans = interLeaveQueue(q);
    cout << "Queue after Interleaving:" << endl;
    printQueue(ans);
    return 0;
}