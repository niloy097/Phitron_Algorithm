#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 7;
bool visited[N];
ll dist[N];
const ll INF = 1e18 + 7;
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
int main()
{
    int n,m;
    cin >> n >> m;
    vector<Edge> vctr;
    while(m--)
    {
        ll u, v, w;
        cin >> u >> v>> w;
        Edge eg(u, v, w);
        vctr.push_back(eg);
    }
    for(int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    int src;
    cin>>src;
    dist[src] = 0;
    visited[src] = true;
    
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 0; j < vctr.size(); j++)
        {
            Edge eg = vctr[j];
            ll u = eg.u;
            ll v = eg.v;
            ll w = eg.w;
            if(dist[u] != INF and dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                visited[v] = true;
            }
        }
    }
    bool cycl = false;
    for(int i = 0; i < vctr.size(); i++)
    {
        Edge eg = vctr[i];
        ll u = eg.u;
        ll v = eg.v;
        ll w = eg.w;
        if(dist[u] != INF and dist[u] + w < dist[v])
        {
            dist[v] = dist[u] + w;
            cycl = true;
        }
    }
    
    if(cycl)
    {
        cout << "Negative Cycle Detected" << endl;
        int t;
        cin >> t;
        while(t--)
        {
            int desti;
            cin >> desti;
        }
    }
    else
    {
        int t;
        cin >> t;
        while(t--)
        {
            int desti;
            cin >> desti;
            if(!visited[desti])
            {
                cout << "Not Possible" <<endl;
            }
            else
            {
                cout << dist[desti] << endl;
            }
        }
    }
    return 0;
}