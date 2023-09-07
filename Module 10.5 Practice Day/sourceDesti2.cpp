#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+7;
const int INF = 1e8+7;
vector<pair<int,int>> graph[N];
vector<bool> visited(N);
vector<int> distace(N, INF);
void dijkstra(int src)
{
    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    distace[src] = 0;
    pq.push(make_pair(distace[src], src));

    while(!pq.empty()) // O(vertex + edges)
    {
        int parent = pq.top().second;
        pq.pop();

        visited[parent] = true;

        for(pii childPair : graph[parent])
        {
            int child = childPair.first;
            int weight = childPair.second;

            if(visited[child]) continue;

            //Relaxation
            if(distace[child] > distace[parent] + weight)
            {
                distace[child] = distace[parent] + weight;
                pq.push(make_pair(distace[child], child));
            }

        }

    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        // graph[v].push_back(make_pair(u, w));
    }
    int src, d;
    cin >> src >> d;
    dijkstra(src);

    cout << distace[d] << endl;
    return 0;
}