// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, int val)
{
    Node *newnode = new Node(val);

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newnode;
}

void insert_at_any_position(Node *head, int pos, int val)
{
    Node *newnode = new Node(val);

    Node *temp = head;
    int i = 1;
    while (i != pos - 1)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void insert_at_head(Node *&head, int val)
{
    Node *newnode = new Node(val);

    newnode->next = head;
    head = newnode;
}

void print_linked_list(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << nl;
}

void delete_from_any_position(Node *head, int pos)
{
    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    Node *deletenode = temp->next;
    temp->next = temp->next->next;
    delete deletenode;
}

void delete_head(Node *&head)
{
    Node *deletehead = head;
    head = head->next;
    delete deletehead;
}

int main()
{
    Node *head = NULL;
    while (1)
    {
        cout << "Option-01: Insert at Tail of your Linked List\n";
        cout << "Option-02: Print your Linked List\n";
        cout << "Option-03: Insert at any Position\n";
        cout << "Option-04: Delete from any Position\n";
        cout << "Option-05: Terminate \n\n";
        cout << "Select Any Options: ";

        int op;
        cin >> op;

        if (op == 1)
        {
            int val;
            cin >> val;
            insert_at_tail(head, val);
        }
        else if (op == 2)
        {
            print_linked_list(head);
        }
        else if (op == 3)
        {
            int pos, val;
            cout << "Enter position and value: ";
            cin >> pos >> val;
            if (pos == 0)
            {
                insert_at_head(head, val);
            }
            else
            {
                insert_at_any_position(head, pos, val);
            }
        }
        else if (op == 4)
        {
            int pos;
            cout << "Enter Position: ";
            cin >> pos;
            if (pos == 0)
            {
                delete_head(head);
            }
            else
            {
                delete_from_any_position(head, pos);
            }
        }
    }

    return 0;
}