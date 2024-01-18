#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node *copyRandomList(Node *head)
{
    if (!head)
        return head;
    // step 1: Clone A to A'
    Node *it = head;
    while (it != nullptr)
    {
        // iterating over old head
        Node *clonedNode = new Node(it->val);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = clonedNode->next;
    }
    // step 2: Assigning random links with the help of A
    it = head;
    while (it)
    {
        Node *cloneNode = it->next;
        cloneNode->random = it->random ? it->random->next : nullptr;
        it = it->next->next;
    }
    // step:3
    //  Detaching A from A'
    it = head;
    Node *cloneHead = it->next;
    while (it)
    {
        Node *cloneNode = it->next;
        it->next = it->next->next;
        if (cloneNode->next)
        {
            cloneNode->next = cloneNode->next->next;
        }
        it = it->next;
    }
    return cloneHead;
}
void prinLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Random pointers: 1 -> 3, 2 -> 1, 3 -> 2
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;
    return 0;
}