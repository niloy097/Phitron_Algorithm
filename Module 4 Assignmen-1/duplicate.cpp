#include<bits/stdc++.h>
using namespace std;
int main()
{


    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int key;
    cin >> key;

    bool justify = false;
    int low = 0;
    int high = v.size() - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(key == v[mid])
        {
            if((mid >= 0 && v[mid+1] == key) || (mid < v.size() && v[mid -1] == key))
            {
                justify = true;
                break;
            }
            else
            {
                justify = false;
                break;
            }
        }
        else if(key < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if(justify) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}