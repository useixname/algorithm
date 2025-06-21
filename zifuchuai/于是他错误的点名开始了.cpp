#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>
#define re register
struct Trie
{
    bool count;
    int next[26];
    bool exist;
} a[500100];
int top(1);
char str[60];
int n, m;
char buf[10000], *p = buf, *end = buf;
int lent;
inline char getChar()
{
    if (p == end)
    {
        if (feof(stdin))
            return '\0';
        p = buf, end = buf + fread(buf, 1, 10000, stdin);
    }
    return *(p++);
}
inline void getString(char *str)
{
    lent = 0;
    char _c;
    while (!isalpha(_c = getChar()))
        ;
    do
        str[lent++] = _c;
    while (isalpha(_c = getChar()));
    str[lent] = '\0';
    return;
}
inline void getNum(int &x)
{
    x = 0;
    char c;
    while (!isdigit(c = getChar()))
        ;
    do
        x = x * 10 + (c - '0');
    while (isdigit(c = getChar()));
    return;
}
inline void Trie_insert()
{
    int num(0), root = 1;
    for (re int i = 0; str[i]; ++i)
    {
        num = str[i] - 'a';
        if (!a[root].next[num])
            a[root].next[num] = ++top;
        root = a[root].next[num];
    }
    a[root].exist = true;
    return;
}
inline int Trie_search()
{
    int num(0), root = 1;
    for (re int i = 0; str[i]; ++i)
    {
        num = str[i] - 'a';
        if (!a[root].next[num])
            return 0;
        root = a[root].next[num];
    }
    if (!a[root].exist)
        return 0;
    else if (a[root].count)
        return 2;
    a[root].count = true;
    return 1;
}
int main()
{
    getNum(n);
    for (re int i = 1; i <= n; ++i)
    {
        memset(str, 0, sizeof str);
        getString(str);
        Trie_insert();
    }
    getNum(m);
    scanf("%d", &m);
    for (re int i = 1; i <= m; ++i)
    {
        memset(str, 0, sizeof str);
        getString(str);
        int tmp = Trie_search();
        if (tmp == 0)
            printf("WRONG\n");
        else if (tmp == 1)
            printf("OK\n");
        else if (tmp == 2)
            printf("REPEAT\n");
    }
    return 0;
}