#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
  public:
    ll val;
    Node *next;
    Node(ll val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_head(Node *&head, ll value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void inser_tail(Node *&head, ll value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete_node(Node *&head, int pos)
{
    if (head == NULL || pos < 0)
        return;
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *run = head;
    for (int i = 0; i < pos - 1 && run != NULL; ++i)
    {
        run = run->next;
    }
    if (run == NULL || run->next == NULL)
        return;
    Node *temp = run->next;
    run->next = run->next->next;
    delete temp;
}

void print_List(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int tc;
    cin >> tc;
    Node *head = NULL;

    for (int i = 0; i < tc; ++i)
    {
        int x;
        ll v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_head(head, v);
        }
        else if (x == 1)
        {
            inser_tail(head, v);
        }
        else if (x == 2)
        {
            delete_node(head, v);
        }
        print_List(head);
    }

    return 0;
}