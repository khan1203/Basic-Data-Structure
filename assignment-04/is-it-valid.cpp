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

int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        stack<char> st;
        int i = 0, n0 = 0, n1 = 0;
        while (str[i] != '\0')
        {
            st.push(str[i]);
            i++;
        }

        while (!st.empty())
        {
            // cout << st.top() << " ";
            if(st.top()=='0') n0++;
            else n1++;
            st.pop();
        }

        if(n0==n1)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}