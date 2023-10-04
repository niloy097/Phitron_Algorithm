#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int low = 0;
    int high = n - 1;
    bool flag = false;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == target)
        {
            flag = true;
            break;
        }
        else if(target < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(flag) cout << "Found" << endl;
    else cout << "Not Found" << endl;
    return 0;
}