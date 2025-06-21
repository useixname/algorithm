#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int len = s1.size();
    int num = 0; // 计数器
    int l = len, r = 0;
    // 寻找第一出现和最后一个出现#的位置并记录
    for (int i = 0; i < len; i++)
    {
        if (s1[i] == '#' || s2[i] == '#')
        {
            l = min(l, i);
            r = max(r, i);
        }
    }
    for (int i = l; i < r; i++)
    {
        // 第一种情况的判断
        if (s1[i] == '#' && s1[i + 1] == '.' && s2[i] == '.')
        {
            num++;
            s1[i + 1] = '#';
        }
        // 第二种情况的判断
        if (s1[i] == '.' && s2[i + 1] == '.' && s2[i] == '#')
        {
            num++;
            s2[i + 1] = '#';
        }
        // 第三种情况的判断
        if (s1[i] == '#' && s2[i] == '#' && s2[i + 1] == '.' && s1[i + 1] == '.')
        {
            int p = i, q = i;
            for (int j = i + 1; j <= r; j++)
            {
                if (s1[j] == '#')
                {
                    p = j;
                    break;
                }
                if (s2[j] == '#')
                {
                    q = j;
                    break;
                }
            }
            if (p >= q)
            {
                s1[i + 1] = '#';
                num++;
            }
            else
            {
                s2[i + 1] = '#';
                num++;
            }
        }
    }
    cout << num;
    return 0;
}