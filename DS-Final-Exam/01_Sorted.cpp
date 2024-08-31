// by Khan Muhammad Rifat (CSE, BUBT)
#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define PI 2 * acos(0.0)
using namespace std;

int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        set<int> s;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }

        for(auto it:s){
            cout<<it<<" ";
        }

        cout<<nl;
    }
    return 0;
}