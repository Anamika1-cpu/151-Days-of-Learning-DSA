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

bool checkPalindrome(Node *head)
{
    Node *temp = head;
    string ans = "";
    while (temp != NULL)
    {
        char a = char(temp->data) + 0;
        ans += a;
        temp = temp->next;
    }
    string b = ans;
    reverse(ans.begin(), ans.end());
    if (ans.compare(b) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// tortoise method/ fast-slow pointer approach
Node *findMidNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node *reverseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
bool compareList(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}
bool method2PalindromeCheck(Node *head)
{
    // step1. find mid node in ll
    Node *midNode = findMidNode(head);
    // step2. set head 2(dividing ll in 2)
    Node *head2 = midNode->next;
    midNode->next = NULL;
    // step3. Reverse the second half
    Node *revHead = reverseLinkedList(head2);
    // step4. comapre both linked lists
    bool ans = compareList(head, revHead);
    return ans;
}
int main()
{
    Node *head = new Node(6);
    head->next = new Node(5);
    head->next->next = new Node(4);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    cout << "Linked List: " << endl;
    printLL(head);
    bool ans = method2PalindromeCheck(head);
    if (ans == false)
    {
        cout << "Linked List is not palindrmoic: " << endl;
    }
    else
    {
        cout << "Linked List is palindrmoic: " << endl;
    }
    return 0;
}