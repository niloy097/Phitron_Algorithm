#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int parentSize[1000];
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
        }
        else
        {
            //A or B can be leader
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    sett(n);
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        unionn(u, v);
    }
    cout << find(6) << endl;
    return 0;
}