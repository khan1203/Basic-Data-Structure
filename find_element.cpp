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
void input_linked_list(Node *&head, Node *&tail)
{
    int val;
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
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

int is_present(Node *head, int x)
{
    Node *temp = head;
    int idx = 0;
    while (temp != NULL)
    {
        if (temp->value == x)
        {
            return idx;
        }
        temp = temp->next;
        idx++;
    }

    return -1;
}

int main()
{
    Fast_io();
    int x, tc;
    cin >> tc;
    while (tc--)
    {
        Node *head = NULL;
        Node *tail = NULL;
        input_linked_list(head, tail);
        cin >> x;
        cout << is_present(head, x) << nl;
    }

    return 0;
}