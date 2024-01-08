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

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "\n";
}

Node *getIntersectionNode(Node *headA, Node *headB)
{
    Node *a = headA;
    Node *b = headB;

    while (a->next && b->next)
    {
        if (a == b) // if both of the linked lists are of same length
            return a;
        a = a->next;
        b = b->next;
    }
    // if both of the linked lists are of same length but there is not intersection in them
    if (a->next == 0 && b->next == 0 && a != b)
    {
        return 0;
    }
    if (a->next == 0)
    {
        // B LL is larger or equal
        //  we need find out how much bigger the LL is
        int blength = 0;
        while (b->next)
        {
            blength++;
            b = b->next;
        }
        while (blength--)
        {
            headB = headB->next;
        }
    }
    else
    {
        // A LL is larger
        //  we need find out how much bigger the LL is
        int alength = 0;
        while (a->next)
        {
            alength++;
            a = a->next;
        }
        while (alength--)
        {
            headA = headA->next;
        }
    }
    // finding the intersecting point
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main()
{
    // Creating nodes for the first linked list
    Node *a1 = new Node(1);
    Node *a2 = new Node(5);
    Node *a3 = new Node(3);

    // Creating nodes for the second linked list
    Node *b1 = new Node(5);
    Node *b2 = new Node(6);

    // Intersecting node
    Node *intersect = new Node(5);

    // Connecting nodes for the first linked list
    a1->next = a2;
    a2->next = a3;
    a3->next = intersect;

    // Connecting nodes for the second linked list
    b1->next = b2;
    b2->next = intersect; // Connecting to the same intersecting node

    // Print the linked lists
    std::cout << "First Linked List: ";
    printLL(a1);

    std::cout << "Second Linked List: ";
    printLL(b1);
    Node *ans = getIntersectionNode(a1, b1);
    cout << "The intersecting node is " << endl;
    cout << ans->data << endl;
    return 0;
}