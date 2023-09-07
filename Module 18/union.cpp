#include<bits/stdc++.h>
using namespace std;
int parent[1000];
void sett(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = -1;
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
        parent[leaderB] = leaderA;
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
    cout << find(5);
    return 0;
}