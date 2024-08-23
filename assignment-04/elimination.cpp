// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

void Fast_io()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}

class Node
{
public:
    int value;
    Node *next;
    Node(int val) : value(val), next(NULL) {}
};

bool isValidString(string str)
{
    stack<char> s1;
    stack<char> s2;

    int i = 0;
    while (str[i] != '\0')
    {
        s1.push(str[i]);
        i++;
    }

    while (!s1.empty())
    {
        if (!s2.empty() && (s1.top() == '0' && s2.top() == '1'))
        {
            s1.pop();
            s2.pop();
        }
        else
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    return s2.empty();
}

int main()
{

    int tc;
    cin >> tc;
    stack<char> s1;
    while (tc--)
    {
        string str;
        cin >> str;
        if (str.length() % 2 == 0)
        {
            if (isValidString(str))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}