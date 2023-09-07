#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pa;
const int N = 1e5+7;
const int INF = 1e9+7;
vector<pa> graph[N];
int n, m;
vector<int>dist(N, INF);

void bellmanFord(int src)
{
    dist[src] = 0;

    for(int i = 1; i < n; i++)
    {
        for(int parent = 1; parent <= n; parent++)
        {
            for(auto childPr : graph[parent])
            {
                int child = childPr.first;
                int weight = childPr.second;

                if(dist[parent] != INF && dist[child] > dist[parent] + weight)
                {
                    dist[child] = dist[parent] + weight;
                }
            }
        }
    }
}
int main()
{   
    cin >> n >> m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v>> w;
        graph[u].push_back({v,w});
    }

    int src; 
    cin >> src;
    bellmanFord(src);

    int q; 
    cin >> q;
    while(q--)
    {
        int des, weight;
        cin >> des >> weight;
        dist[des] <= weight ? cout << "YES" << endl : cout << "NO" << endl;
        
    }

    return 0;
}