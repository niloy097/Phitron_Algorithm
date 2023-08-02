//PL: https://www.codingninjas.com/studio/problems/second-largest-element-in-the-array_873375?leftPanelTab=0

/*

#include <bits/stdc++.h>
int highest(vector<int>&arr)
{
    int hg = INT_MIN;
    for(int i = 0; i < arr.size(); i++)
    {
        hg = max(hg, arr[i]);
    }
    return hg;
}
int findSecondLargest(int n, vector<int> &arr)
{
    int x = highest(arr);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x) arr[i] = -1;
    }
    int secondMax = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != -1)
        {
            secondMax = max(secondMax, arr[i]);
        }
    }
    if(secondMax == INT_MIN) return -1;
    return secondMax;
}

*/