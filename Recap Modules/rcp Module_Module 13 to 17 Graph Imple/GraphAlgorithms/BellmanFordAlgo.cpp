#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
class Edge
{
    public:
        int u, v, w;
        Edge(int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
vector<Edge> EdgeList;
vector<int> dist(N, INF);
int n, m;
void bellmanFord(int src)
{
    dist[src] = 0;
    for(int i = 1; i <= n - 1; i++)
    {
        for(auto ed : EdgeList)
        {
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if(dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
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
        cin >> u >> v >> w;
        Edge eg(u, v, w);
        EdgeList.push_back(eg);
    }
    bellmanFord(1);
    for(int  i= 1; i <= n; i++)
    {
        cout << "The Dist of Node-> " << i << " : " << dist[i] << endl;
    }
    return 0;
}