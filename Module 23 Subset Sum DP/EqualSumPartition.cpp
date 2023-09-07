#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s += arr[i];
    }
    if(s % 2 == 0) // 2x
    {
        int sum = s / 2;
        bool dp[n+1][sum + 1];
        dp[0][0] = true;
        for(int i = 1; i <= sum; i++)
        {
            dp[0][i] = false;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                if(arr[i - 1] <= j)
                {
                    bool op1 = dp[i - 1][j - arr[i - 1]];
                    bool op2 = dp[i -1][j];
                    dp[i][j] = op1 || op2;
                }
                else
                {
                    bool op2 = dp[i - 1][j];
                    dp[i][j] = op2;
                }
            }
        }
        if(dp[n][sum]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}