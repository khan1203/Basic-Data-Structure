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
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
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

void is_Duplicate_exist(Node *head)
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
    {
        for (Node *j = temp->next; j != NULL; j = j->next)
        {
            if (temp->value == j->value)
            {
                cout << "YES\n";
                return;
            }
        };
    }
    cout << "NO" << nl;
}

int main()
{
    int val;
    Node *head = NULL;

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        input_Linked_List(head, val);
    }

    is_Duplicate_exist(head);

    return 0;
}