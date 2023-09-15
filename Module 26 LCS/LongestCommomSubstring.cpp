#include<bits/stdc++.h>
using namespace std;

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();
    int dp[n+1][m+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int mx = 0;
    int ci, cj;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(dp[i][j] > mx)
            {
                mx = dp[i][j];
                ci = i, cj = j;
            }
        }
        
    }
    string ans = "";
    while(ci != 0 && cj != 0)
    {
        if(x[ci - 1] == y[cj - 1]) //checking mathced char
        {
            ans += x[ci - 1];
            ci--;
            cj--;
        }
        else
        {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}