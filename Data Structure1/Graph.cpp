#include <bits/stdc++.h>
using namespace std;
const int MAX_INT = 0x7fffffff;
typedef struct ENode *PENode;
struct ENode
{
    char a1, a2;
    int weight;
};
typedef PENode Edge;

typedef struct GNode *PGNode;
struct GNode
{
    int node;
    int edge;
    int G[30][30];
    bool N[30];
    char A[30];
};
typedef PGNode GMap;

bool vis[30];
void zeroVisit(int n)
{
    for (int i = 0; i < n; i++)
        vis[i] = 0;
}
void creatMap(GMap MGraph)
{
    for (int i = 0; i <= 25; i++)
    {
        MGraph->N[i] = 0;
        for (int j = 0; j <= 25; j++)
        {
            MGraph->G[i][j] = MAX_INT;
        }
    }
}
void insertEdge(GMap MGraph, Edge e)
{
    int c = e->a1 - 'A';
    int b = e->a2 - 'A';
    MGraph->N[c] = 1;
    MGraph->N[b] = 1;
    MGraph->G[c][b] = MGraph->G[b][c] = e->weight;
}
void DFS(GMap MGraph, int node)
{
    cout << " " << (char)(node + 'A');
    vis[node] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (MGraph->G[node][i] < MAX_INT)
        {
            if (vis[i] == 0)
            {
                DFS(MGraph, i);
            }
        }
    }
}
void BFS(GMap MGraph, int node)
{
    queue<int> q1;
    queue<int> q2;
    vis[node] = 1;
    q1.push(node);
    while (!q1.empty() || !q2.empty())
    {
        while (!q1.empty())
        {
            int n;
            n = q1.front();
            cout << " " << (char)(n + 'A');
            for (int i = 0; i < 26; i++)
            {
                if (MGraph->G[n][i] < MAX_INT)
                {
                    if (vis[i] == 0)
                    {
                        q2.push(i);
                        vis[i] = 1;
                    }
                }
            }
            q1.pop();
        }
        while (!q2.empty())
        {
            int n;
            n = q2.front();
            cout << " " << (char)(n + 'A');
            for (int i = 0; i < 26; i++)
            {
                if (MGraph->G[n][i] < MAX_INT)
                {
                    if (vis[i] == 0)
                    {
                        q1.push(i);
                        vis[i] = 1;
                    }
                }
            }
            q2.pop();
        }
    }
}
void inAndout(GMap MGraph)
{
    for (int i = 0; i < 26; i++)
    {
        if (MGraph->N[i] == 1)
        {
            cout << endl
                 << (char)(i + 'A') << ':';
            int temp = 0;
            for (int j = 0; j < 26; j++)
            {
                if (MGraph->G[i][j] < MAX_INT)
                    temp++;
            }
            cout << temp;
        }
    }
}
int main()
{
    GMap MGraph;
    MGraph = (GMap)malloc(sizeof(GNode));
    cin >> MGraph->node >> MGraph->edge;
    creatMap(MGraph);
    Edge e1;
    e1 = (Edge)malloc(sizeof(ENode));
    for (int i = 0; i < MGraph->edge; i++)
    {
        cin >> e1->a1 >> e1->a2 >> e1->weight;
        insertEdge(MGraph, e1);
    }
    int temp = 0;
    for (int i = 0; i < 26; i++)
    {
        if (MGraph->N[i] == 1)
        {
            temp = i;
            break;
        }
    }
    zeroVisit(26);
    cout << "DFS:";
    DFS(MGraph, temp);
    cout << endl;
    cout << "BFS:";
    zeroVisit(26);
    BFS(MGraph, temp);
    inAndout(MGraph);
    return 0;
}