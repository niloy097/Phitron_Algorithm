#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, marks;
        cin >> n >> marks;
        int val[n];
        for(int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        int s = 1000 - marks;
        bool dp[n+1][s+1];
        dp[0][0] = true;
        for(int i = 1; i <= s; i++)
        {
            dp[0][i] = false;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= s; j++)
            {
                if(val[i - 1] <= j)
                {
                    bool op1 = dp[i][j - val[i - 1]];
                    bool op2 = dp[i - 1][j];
                    dp[i][j] = op1 or op2;
                }
                else
                {
                    bool op2 = dp[i - 1][j];
                    dp[i][j] = op2;
                }
            }
        }
        if(dp[n][s]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}