#include <bits/stdc++.h>
using namespace std;

// creating a Node
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

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode; // Set the last node to point back to the starting node
}

bool detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = new Node();
    head->data = 1;

    head->next = new Node();
    head->next->data = 2;

    head->next->next = new Node();
    head->next->next->data = 3;

    head->next->next->next = new Node();
    head->next->next->next->data = 4;

    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 5;

    makeCycle(head, 2); // Creating a loop at position 2
    cout << detectLoop(head) << endl;
    return 0;
}
