#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void prinLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
vector<int> nodesBetweenCriticalPoints(Node *head)
{
    // initalising min and max distance
    vector<int> ans = {-1, -1};
    // if we don't have prev and next then we cannot chcek for critical point
    Node *prev = head;
    if (!prev)
        return ans;
    Node *curr = head->next;
    if (!curr)
        return ans;
    Node *nxt = head->next->next;
    if (!nxt)
        return ans;

    int firstCp = -1;
    int lastCp = -1;
    int minDist = INT_MAX;
    int i = 1;

    while (nxt != NULL)
    {
        // checking for critical point
        bool isCp = ((curr->data > prev->data && curr->data > nxt->data) ||
                     (curr->data < prev->data && curr->data < nxt->data))
                        ? true
                        : false;

        if (isCp && firstCp == -1)
        {
            // found the first critical point
            firstCp = i;
            lastCp = i;
        }
        else if (isCp)
        {
            minDist = min(minDist, i - lastCp);
            lastCp = i;
        }
        i++;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }
    if (firstCp == lastCp)
    {
        // only 1 cp has been found
        return ans;
    }
    else
    {
        ans[0] = minDist;
        ans[1] = lastCp - firstCp;
    }
    return ans;
}
int main()
{
    Node *head = new Node();
    head->data = 1;

    head->next = new Node();
    head->next->data = 3;

    head->next->next = new Node();
    head->next->next->data = 2;

    head->next->next->next = new Node();
    head->next->next->next->data = 1;

    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 9;

    cout << " LinkedList " << endl;
    prinLinkedList(head);
    cout << endl;
    cout << "The minimum and maximum ditsnace between the critical points are " << endl;
    vector<int> ans = nodesBetweenCriticalPoints(head);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}