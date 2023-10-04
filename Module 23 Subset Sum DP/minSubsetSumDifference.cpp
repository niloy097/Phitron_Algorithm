#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>> n;
    int arr[n];
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int dp[n + 1][sum + 1];
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
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }
    vector<int> v;
    
    for(int i = 0; i <= n; i++)
    {
        for(int  j= 0; j <= sum; j++)
        {
            // // Observation the table
            // if(dp[i][j] == 1) cout << j << " ";
            // else cout << dp[i][j] << " ";

            if(dp[i][j] == 1) v.push_back(j);
        }
        // cout << endl;
    }
    int ans = INT_MAX;
    for(int val : v) // val = first subset s1
    {
        int s1 = val;
        int s2 = sum - s1;
        ans = min(ans, abs(s1 - s2)); // here s1 - s2 = subset sum difference.
    }
    cout << ans << endl; // minmum diff = ans
    return 0;
}

/*Input output observations


in: 
4
1 5 4 11

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 1 0 0 0 5 6 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 1 0 0 4 5 6 0 0 9 10 0 0 0 0 0 0 0 0 0 0 0 
0 1 0 0 4 5 6 0 0 9 10 11 12 0 0 15 16 17 0 0 20 21 






*/