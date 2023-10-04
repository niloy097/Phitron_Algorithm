#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int i = 0;
        int j = n - 1;
        int maxArea = INT_MIN;
        int lastMax = INT_MIN;
        int x, y;
        while(i <= j)
        {
            if(arr[i] < arr[j])
            {
                int area = 
            }
           
            if(lastMax > area)
            {
                x = i;
                y = j;
            }
            lastMax = area;
            i++;
            j--;

        }
        cout << i << " " << j << endl;
    }
    return 0;
}