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

int main()
{
    Fast_io();

    ll tc;
    cin >> tc;
    queue<string> q;
    while (tc--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            string name;
            cin >> name;
            q.push(name);
        }
        else if (x == 1)
        {
            if (q.empty())
            {
                cout << "Invalid" << nl;
            }
            else
            {
                cout << q.front() << nl;
                q.pop();
            }
        }
    }
    return 0;
}