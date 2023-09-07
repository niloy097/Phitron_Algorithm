#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pa;
const int N = 1e3 + 7;
int n, m;
char graph[N][N];
int visited[N][N];
vector<int> areas;
int area = 0;
vector<pa> direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int si, int sj)
{
    visited[si][sj]= true;
    area++;
    for(auto dir : direction)
    {
        int ci = si + dir.first;
        int cj = sj + dir.second;

        if(!visited[ci][cj] && isValid(ci, cj) && graph[ci][cj] != '-')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int  j =  0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    for(int i=0; i < n; i++)
    {
        for(int  j =0; j < m; j++)
        {
            if(isValid(i, j) && !visited[i][j] && graph[i][j] != '-')
            {
                dfs(i, j);
                areas.push_back(area);
                area = 0;
            }
        }
    }
    if(areas.empty()) cout << -1;
    else
    {
        sort(areas.begin(), areas.end());
        cout << areas[0] << endl;
    }
    return 0;
}