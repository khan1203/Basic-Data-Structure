// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

void Fast_io()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

class Node
{
public:
    int val;
    Node *next;
    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
    }
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void input_Linked_List(Node *&head, int val)
{
    Node *newnode = new Node(val);

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void print_linked_list(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout<<nl;
}

int main()
{
    int val;
    Node *head = NULL;

    int count=0;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;

        count++;
        input_Linked_List(head, val);
    }

    print_linked_list(head);
    cout<<count<<nl;

    return 0;
}