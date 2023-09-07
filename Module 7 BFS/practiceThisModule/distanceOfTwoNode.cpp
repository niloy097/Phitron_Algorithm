#include<bits/stdc++.h>
using namespace std;
vector<int> adjList[100];
bool visted[100];
int level[100];
void bfs(int src)
{
    queue<int> qu;
    visted[src] = true;
    qu.push(src);
    while(!qu.empty())
    {
        int parent = qu.front();
        qu.pop();
        for(int child : adjList[parent])
        {
            if(!visted[child])
            {
                qu.push(child);
                visted[child] = true;
                level[child] = level[parent] + 1;
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
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int start, end;
    cin >> start >> end;

    bfs(start);
    cout << level[end] << endl;

    memset(visted, false, sizeof(visted));
    
    return 0;
}

/*
7
11
1 4
1 2
1 6
4 7
4 2
2 5
2 3
6 3
6 7
7 5
5 3

*/