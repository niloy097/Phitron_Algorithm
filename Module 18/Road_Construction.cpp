#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int parent[N];
int parentSize[N];
void sett(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int find(int node) // we can find leader by using this fucntion
{
    while(parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
int mx = 0;
void unionn(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);

    if(leaderA != leaderB)
    {   
        //Union by size
        if(parentSize[leaderA] > parentSize[leaderB])
        {
            //A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
            mx = max(mx, parentSize[leaderA]);
        }
        else
        {
            //A or B can be leader
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
            mx = max(mx, parentSize[leaderB]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    sett(n);
    int cmpCnt = n;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        int leaderA = find(u);
        int leaderB = find(v);
        if(leaderA != leaderB)
        {
            cmpCnt--;
            unionn(u, v);


        }
        cout << cmpCnt << " " << mx << endl;
    }
    return 0;
}