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
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
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
    int i = n, j = m;
    string ans = "";
    while(i!=0 && j!=0)
    {
        if(x[i-1] == y[j-1]) // char mathched
        {
            ans+=x[i-1]; //appending matched char to ans stirng
            i--;
            j--; // going up diagonal
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j]) // left cell is maximum
            {
                j--; // going left
            }
            else
            {
                i--; // going up
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}