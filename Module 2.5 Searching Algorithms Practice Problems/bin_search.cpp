//Problem Link: https://leetcode.com/problems/binary-search/


/*


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int ans = -1;
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
            {
                ans = mid;
                return ans;
            }
            else if(target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};


*/