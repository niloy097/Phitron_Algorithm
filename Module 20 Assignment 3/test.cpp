#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 2;
bool vis[N];
long long dis[N];
const ll INF = 1e18 + 2;

class Edge{
    public:
        int u;
        int v;
        int w;
        Edge(int u,int v,int w){
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
int main(){
    vector<Edge> vec;
    int n,e;
    cin>>n>>e;
    while(e--){
        ll a, b, w;
        cin>>a>>b>>w;
        Edge ed(a, b, w);
        vec.push_back(ed);
    }
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }
    int s;
    cin>>s;
    dis[s] = 0;
    vis[s] = true;
    for(int i = 1; i <= n - 1; i++){
        for(int j = 0; j < vec.size(); j++){
            Edge ed = vec[j];
            ll a = ed.u;
            ll b = ed.v;
            ll w = ed.w;
            if(dis[a] != INF and dis[a] + w < dis[b]){
                dis[b] = dis[a] + w;
                vis[b] = true;
            }
        }
    }
    bool cycle = false;
    for(int i = 0; i < vec.size(); i++){
        Edge ed = vec[i];
        ll a = ed.u;
        ll b = ed.v;
        ll w = ed.w;
        if(dis[a] != INF and dis[a] + w < dis[b]){
            dis[b] = dis[a] + w;
            cycle = true;
        }
    }
    
    if(cycle == true){
        cout<<"Negative Cycle Detected"<<endl;
        int t;
        cin>>t;
        while(t--){
            int des;
            cin>>des;
        }
    }
    else{
        int t;
        cin>>t;
        while(t--){
            int des;
            cin>>des;
            if(vis[des] == false){
                cout<<"Not Possible"<<endl;
            }
            else{
                cout<<dis[des]<<endl;
            }
        }
    }
    return 0;
}