//Problem Link: https://leetcode.com/problems/missing-number/submissions/
/*


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sumInRange = (len * (len + 1))/2;
        cout << sumInRange << endl;
        // Sn = N * (N + 1) / 2
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        return sumInRange - sum;
    }
};

*/