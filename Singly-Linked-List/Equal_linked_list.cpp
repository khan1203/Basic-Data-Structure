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
    int val, co=0;
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

void print_reverse(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    // Fast_io();
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    int l1 = input_linked_list(head1, tail1);
    int l2 = input_linked_list(head2, tail2);
    if(l1==l2){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}