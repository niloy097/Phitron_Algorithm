//Problem Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/submissions/

/*


class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        for(int val : nums)
        {
            if(val > 0) pos++;
            if(val < 0) neg++;
        }

        return max(pos, neg);
    }
};




*/