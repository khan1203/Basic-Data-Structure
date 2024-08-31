#include <bits/stdc++.h>
using namespace std;

void print()
{
    string sentence;
    getline(cin, sentence);
    string word;
    stringstream ss(sentence);
    map<string, int> mp;

    int maxCount = 0;
    string maxStr;
    while (ss >> word)
    {
        mp[word]++;
        if (mp[word] > maxCount)
        {
            maxCount = mp[word];
            maxStr = word;
        }
    }

    cout << maxStr << " " << maxCount << endl;
}

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--)
    {
        print();
    }
    return 0;
}