//Problem Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/submissions/

/*


class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> indics;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                indics.push_back(i);
            }
        }
        sort(indics.begin(),indics.end());
        return indics;
    }
};


*/