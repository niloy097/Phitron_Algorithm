#include <bits/stdc++.h>
using namespace std;
int knapSack(int n, int s, int *v, int *w) // O(2^n)
{
    //Base case
    if(n == 0 or s == 0) return 0;
    if (w[n - 1] <= s)
    {
        int op1 = knapSack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = knapSack(n - 1, s, v, w);
        return max(op1, op2);
    }
    else
    {
        return knapSack(n - 1, s, v, w);
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
    cout << knapSack(n, s, value, weight) << "\n";
    return 0;
}