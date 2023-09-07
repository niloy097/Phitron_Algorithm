#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> graph[N];
vector<bool> visited(N, false);
vector<int> dist(N);
vector<int> prnt(N, -1);
void bfs(int src)
{
    queue<int> qu;
    dist[src] = 0;
    qu.push(src);
    visited[src] = true;
    while (!qu.empty())
    {
        int parent = qu.front();
        qu.pop();

        for(int child : graph[parent])
        {
            if(!visited[child])
            {
                qu.push(child);
                visited[child] = true;
                dist[child] = dist[parent] + 1;
                prnt[child] = parent;
            }
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
    
    // for(int i = 1; i <= n; i++)
    // {
    //     cout << "Parent of " << i << " : " << prnt[i] << endl;
    // }

    int src, desti;
    cin >> src >> desti;
    bfs(src);
    vector<int> path;
    int cur = desti;
    while(cur != -1)
    {
        path.push_back(cur);
        cur = prnt[cur];
    }
    // path.push_back(cur);
    reverse(path.begin(), path.end());
    for(int pp : path) cout << pp << " ";
    cout << endl;
    return 0;
}