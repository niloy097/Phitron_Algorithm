//PB: https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int dp[N];
int solve(int *arr, int n) // topDown Dp, O(n)
{
    if(n == 1) return 0; // base case
    if(dp[n] != -1) return dp[n]; // memoization
    else if(n == 2) return dp[n] = abs(arr[2] - arr[1]); // save + return
    else
    {
        int choice1 = solve(arr, n - 1) + abs(arr[n] - arr[n-1]);
        int choice2 = solve(arr, n - 2) + abs(arr[n] - arr[n-2]);
        return dp[n] = min(choice1, choice2); //save + return;
    }

}
int main()
{
    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        cin >> arr[i];
    }
    cout << solve(arr, n) << "\n";
    return 0;
}