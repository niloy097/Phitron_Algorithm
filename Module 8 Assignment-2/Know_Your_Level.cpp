#include <bits/stdc++.h>
using namespace std;
const int N =1e5+5;
vector <int> graph[N];
bool visited[N];
vector <int> lvl(N);
vector <int> lvlNodes[N];
void bfs(int src,int level)
{

    queue<int> qu;
    visited[src] = true;
    qu.push(src);
    lvlNodes[src].push_back(src);
    while(!qu.empty())
    {
        int parent = qu.front();
        qu.pop();
        for(int child : graph[parent])
        {
            if(!visited[child])
            {
                qu.push(child);
                lvl[child] = lvl[parent] + 1;
                visited[child] = true;
                if(lvl[child] == level)
                {
                    lvlNodes[level].push_back(child);
                }
            }
            
        }
    }
}

int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int level;
    cin >> level;
    bfs(0, level);
    sort(lvlNodes[level].begin(), lvlNodes[level].end());
    if(lvlNodes[level].empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for(int val : lvlNodes[level])
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}