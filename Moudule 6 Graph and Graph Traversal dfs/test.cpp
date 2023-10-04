#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1005];
vector<bool> visited(1005,false);
void dfs(int parent)
{
    visited[parent] = true;
    cout << parent <<  " ";
    for(int child : graph[parent])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }
    dfs(1);
    return 0;
}