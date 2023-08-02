//PL: https://www.codingninjas.com/studio/problems/find-duplicate-in-array_1112602?leftPanelTab=0

/*

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	//map<int, int> mp;
	for(int i = 0; i < arr.size(); i++)
	{
		mp[arr[i]]++;
	}
	for(auto it = mp.begin(); it != mp.end(); it++)
	{
		if(it->second > 1) return it->first;
	}//
    //another way using two pointers
	//sort(arr.begin(), arr.end());
	int i = 0;
	int j = 1;
	while(j < arr.size())
	{
		if(arr[i] != arr[j]) 
		{
			i = j;
			j++;
		}
		else if(arr[i] == arr[j])
		{
			return arr[i];
			j++;
		}
	}
    //
}


*/