#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int dp[N][N];
int knapSack(int n, int s, int *v, int *w) // O(n * s)
{
    //Base case
    if(n == 0 or s == 0) return 0;
    if(dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (w[n - 1] <= s)
    {
        int op1 = knapSack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = knapSack(n - 1, s, v, w);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = knapSack(n - 1, s, v, w);
    }
}
void sett(int n, int s)
{
    for(int  i= 0; i <= n; i++)
    {
        for(int  j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int value[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    int s;
    cin >> s;
    sett(n,s);
    cout << knapSack(n, s, value, weight) << "\n";
    // for(int i = 0; i <= n; i++)
    // {
    //     for(int j = 0; j <= s; j++)
    //     {
    //         cout << dp[n][s] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}