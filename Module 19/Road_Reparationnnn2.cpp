#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
        int u, v, w;
        Edge(int u, int v, int w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
bool cmp(Edge u, Edge v)
{
    return u.w < v.w;
}
const int N = 1e5 + 7;
int parent[N];
int parentSize[N];
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
    vector<Edge> vctr;
    vector<Edge> ans;
    sett(n);
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vctr.push_back(Edge(u, v, w));
    }
    sort(vctr.begin(), vctr.end(), cmp);
    for(Edge val : vctr)
    {
        int u = val.u;
        int v = val.v;
        int w = val.w;

        int leaderU = find(u);
        int leaderV = find(v);
        if(leaderU == leaderV) continue; //checking cycle 
        ans.push_back(val); // pushing edges which are not forming cycle
        unionn(u, v);
    }
    long long sum = 0;
    for(Edge val : ans)
    {
        sum += (long long)val.w;
    }
    if(ans.size() == (n - 1))
    {
        cout << sum << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}