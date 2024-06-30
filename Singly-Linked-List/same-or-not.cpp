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

// Class -----------------------
class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

// Functions ------------------------
int input_linked_list(Node *&head, Node *&tail)
{
    int val, size = 0;
    while (1)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }
    return size;
}

void check(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != NULL)
    {
        if (temp1->value != temp2->value)
        {
            cout << "NO\n";
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    cout << "YES\n";
}

int main()
{
    Fast_io();
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    int ln1 = input_linked_list(head1, tail1);
    int ln2 = input_linked_list(head2, tail2);
    if (ln1 != ln2)
    {
        cout << "NO\n";
    }
    else
    {
        check(head1, head2);
    }
    return 0;
}