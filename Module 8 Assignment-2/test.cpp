#include <bits/stdc++.h>
using namespace std;

const int N =1e5+7;
vector <int> adjacent[N];
bool visited[N];
vector <int> dist(N,-1);
vector <int > levelNode[N];


void find_shop_list(int src,int level){

    queue <int > q;
    visited[src]=true;
    q.push(src);

    levelNode[src].push_back(src);

    dist[src]=0;

    while (!q.empty()){
        int u=q.front();
        q.pop();
        for(int v : adjacent[u]){
            if(visited[v]) continue;
            q.push(v);
            dist[v]=dist[u]+1;
            visited[v]=true;
            if(dist[v]==level){
                levelNode[level].push_back(v);
            }
        }
    }

}

int main() {
    int v,e;
    cin>>v>>e;
    for(int i =0;i<e;i++){
        int x,y;
        cin >>x>>y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    int level;
    cin >> level;
    find_shop_list(0,level);
    sort(levelNode[level].begin(),levelNode[level].end());

    if(levelNode[level].empty()){
        cout <<"-1"<<endl;
    }
    else {
        for(int j: levelNode[level]){
        cout << j << " ";
    }
    cout <<endl;
    }
    return 0;
}