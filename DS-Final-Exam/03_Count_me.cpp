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
        string sentence;
        getline(cin, sentence);

        stringstream ss(sentence);

        map<string, int> mp;

        int maxCount = 0;
        string maxStr;
        string word;
        while (ss >> word)
        {
            int cnt = mp[word]++;
            cout << cnt << nl;
            if (cnt > maxCount)
            {
                maxCount = cnt;
                maxStr = word;
            }
        }
        cout << maxStr << " " << maxCount << endl;
    }

    return 0;
}
