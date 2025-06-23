class Solution {
public:
    /** 18. 4Sum
        Two Pointers

        time O(N^3)
        space O(1)
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSum(nums, target, 4, 0);
    }

    //// return the nSum
    //// nums has to be sorted
    // n = the sum of the numbers you want to find
    // start = from which index (usually 0)
    vector<vector<int>> nSum(vector<int>& nums, long target, int n, int start)
    {
        int size = nums.size();
        vector<vector<int>> res;

        //// bc. two pointers sol for 2Sum
        if(n == 2)
        {
            int left = start, right = size - 1;
            while(left < right)
            {
                int leftNum = nums[left], rightNum = nums[right];
                int sum = leftNum + rightNum;
                if(sum < target)
                {
                    while(left < right and nums[left] == leftNum)   // remove duplicates
                        ++left;
                }
                else if(sum > target)
                {
                    while(left < right and nums[right] == rightNum) // remove duplicates
                        --right;
                }
                else
                {
                    res.push_back({leftNum, rightNum});
                    while(left < right and nums[left] == leftNum)   // remove duplicates
                        ++left;
                    while(left < right and nums[right] == rightNum) // remove duplicates
                        --right;
                }
            }
        }
        //// for n > 2, fix a number and recursively find (n - 1)Sum
        else
        {
            int i = start;
            while(i < size)
            {
                int curNum = nums[i];
                // we fix curNum, so we want to find some numbers that add up to (target - curNum)
                vector<vector<int>> subRes = nSum(nums, target - curNum, n - 1, i + 1);
                // (n - 1)Sum + curNum is nSum
                for(auto& subR : subRes)
                {
                    subR.push_back(curNum);
                    res.push_back(subR);
                }
                while(i < size and nums[i] == curNum)   // remove duplicates & set i to the start of the next number
                    ++i;
            }
        }
        return res;
    }
};