#include<bits/stdc++.h>
using namespace std;
int fibo(int n) // O(2^n)
{
    if(n == 0 or n == 1) return 1;
    return fibo(n-1) + fibo(n-2); //recurrance function of fibonacci series
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << "\n";
    return 0;
}