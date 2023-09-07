#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3+6;
int visited[N][N];
int level[N][N];
vector<pii> direction =
{make_pair(1, 2), make_pair(1, -2), make_pair(-1, 2), make_pair(-1, -2),
 make_pair(2, 1), make_pair(2, -1), make_pair(-2, 1), make_pair(-2, -1)};
bool isValid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}
void bfs(int si, int sj)
{
    queue<pii> qu;
    qu.push(make_pair(si, sj));
    visited[si][sj] = true;
    level[si][sj] = 0;

    while(!qu.empty())
    {
        pii
    }
}
void resert_level_visit()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int si, sj, di, dj;
        string x, y;
        cin >> x >> y;
        si = x[0] - 'a';
        sj = x[1] - '1';
        
        di = y[0] - 'a';
        dj = y[1] - '1';

        bfs(si, sj);

        cout << level[di][dj] << endl;

        resert_level_visit();
    }
    return 0;
}