#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
int dp[N][N];
int lcs(string x, int n, string y, int m)
{
    if(n == 0 || m == 0) return 0; // if the strings are empty
    if(dp[n][m] != -1) return dp[n][m];
    if(x[n-1] == y[m-1])
    {
        int ans = lcs(x, n - 1, y, m -1);
        return dp[n][m] = ans + 1;
    }
    else
    {
        int op1 = lcs(x, n - 1, y, m);
        int op2 = lcs(x, n, y, m -1);
        return dp[n][m] = max(op1, op2);
    }
}
void sett(int n, int m)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }
}
int main()
{
    string x, y;
    cin >> x >> y;
    sett(x.size(), y.size());
    cout << lcs(x, x.size(), y, y.size()) << endl;

    return 0;
}