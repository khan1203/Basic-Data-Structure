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

int main()
{
    Fast_io();
    int n, m;
    cin >> n >> m;

    if (n == m)
    {
        stack<int> s;
        while (n--)
        {
            int x;
            cin >> x;
            s.push(x);
        }
        queue<int> q;
        while (m--)
        {
            int x;
            cin >> x;
            q.push(x);
        }

        while (!s.empty())
        {
            if (!s.empty() && !q.empty() && s.top() == q.front())
            {
                s.pop();
                q.pop();
            }
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
