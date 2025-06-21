#include <bits/stdc++.h>
using namespace std;

string dfs()
{
    int n;
    string s = "", s1;
    char c;
    while (cin >> c)
    {
        if (c == '[')
        {
            cin >> n;
            s1 = dfs();
            while (n--)
                s += s1;
        }
        else
        {
            if (c == ']')
                return s;
            else
                s += c;
        }
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout << dfs();
    return 0;
}