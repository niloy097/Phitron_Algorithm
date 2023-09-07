#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e9+6;
const int N = 1e5 + 7;
vector<pii> graph[N];
vector<bool> visited(N);
vector<int> prnt(N, -1);
vector<int> dist(N, INF);
void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    visited[src] = true;
    dist[src] = 0;
    pq.push({dist[src], src});
    while(!pq.empty())
    {
        int parent = pq.top().second;
        pq.pop();
        visited[parent] = true;
        for(auto childPr : graph[parent])
        {
            int child = childPr.first;
            int weight = childPr.second;
            if(visited[child]) continue;
            if(dist[child] > dist[parent] + weight)
            {
                dist[child] = dist[parent] + weight;
                prnt[child] = parent;
                pq.push({dist[child], child});
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
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(1);
    // for(int i = 1; i <= n; i++)
    // {
    //     cout << "Dist of Node " << i << " " << dist[i] << endl;
    //     cout << "Prnt of Node " << i << " " << prnt[i] << endl;
    // }
    int desti = 3;
    cout << "Cost " << dist[desti] << endl;
    int curr = desti;
    vector<int> path;
    while(curr != -1)
    {
        path.push_back(curr);
        curr = prnt[curr];
    }

    reverse(path.begin(), path.end());
    cout << "Path printing " << endl;
    for(auto p : path) cout << p << " ";
    return 0;
}