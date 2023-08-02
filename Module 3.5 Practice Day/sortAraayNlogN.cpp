// PL: https://leetcode.com/problems/sort-an-array/
/*
//Merge Sort
class Solution {
public:
    
    vector<int> arr;
    void merge(int l, int r, int mid)
    {
        int leftSize = (mid - l) + 1;
        int L[leftSize + 1];

        int rightSize = r - (mid + 1) + 1;
        int R[rightSize + 1];

        for(int i = l, j = 0; i <= mid; i++,j++)
        {
            L[j] = arr[i];
        }
        for(int i = mid + 1, j = 0; i <= r; i++,j++)
        {
            R[j] = arr[i];
        }

        L[leftSize] = INT_MAX;
        R[rightSize] = INT_MAX;

        int lp, rp;
        lp = 0;
        rp = 0;
        for(int i = l; i <= r; i++)
        {
            if(L[lp] <= R[rp])
            {
                arr[i] = L[lp];
                lp++;
            }
            else
            {
                arr[i] = R[rp];
                rp++;
            }
        }
    }
    void mergeSort(int l, int r)
    {
        if(l == r) return;
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, r, mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) arr.push_back(nums[i]);
        mergeSort(0, n - 1);
        return arr;

    }
};

*/