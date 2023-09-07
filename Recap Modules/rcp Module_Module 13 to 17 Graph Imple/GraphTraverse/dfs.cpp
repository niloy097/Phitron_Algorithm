#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
vector<bool> visited(N);
void dfs(int parent)
{
    cout << parent << " ";
    visited[parent] = true;
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
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    return 0;
}