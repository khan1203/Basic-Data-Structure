// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

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
    int val, co = 0;
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
            co++;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            co++;
        }
    }
    return co;
}

// void print_reverse(Node *n)
// {
//     if (n == NULL)
//     {
//         return;
//     }
//     print_reverse(n->next);
//     cout << n->value << " ";
// }

int main()
{
    // Fast_io();
    Node *head1 = NULL;
    Node *tail1 = NULL;

    int ln = input_linked_list(head1, tail1);
    int mid;
    Node *temp = head1;
    (ln % 2 != 0) ? mid = (ln / 2) + 1 : mid = (ln / 2);
    for (int i = 1; i < mid; i++)
    {
        temp = temp->next;
    }
    if (ln % 2 != 0)
    {
        cout << temp->value << nl;
    }
    else
    {
        cout << temp->value << " " << temp->next->value << nl;
    }
    return 0;
}