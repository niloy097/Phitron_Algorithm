#include<bits/stdc++.h>
using namespace std;
//We can get target sum with this approach
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int diff; cin >> diff;
    int s1 = (diff + sum)/2; // s1 = subset sum
    // if the value of s1 is fractional the required diff
    // is not possible such as (2 + 7)/2, diff 2 is not possible 
    // for this input
    /*
        4
        1 1 2 3
        3

    */
    int dp[n + 1][s1 + 1];
    dp[0][0] = 1;
    for(int i = 1; i <= s1; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= s1; j++)
        {
            if(arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i -1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][s1] << endl;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= s1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}