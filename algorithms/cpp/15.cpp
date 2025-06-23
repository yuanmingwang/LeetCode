class Solution {
public:
    /** 15. 3Sum
        Two Pointers

        time O(N^2)
        space O(1)
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nSum(nums, 3, 0, 0);
    }

    //// return the nSum
    //// nums has to be sorted
    // n = the sum of the numbers you want to find
    // start = from which index (usually 0)
    // target = the target sum you want to find
    vector<vector<int>> nSum(vector<int>& nums, int n, int start, int target)
    {
        int size = nums.size();
        vector<vector<int>> res;
        //// bc. two pointers sol for 2Sum. 
        if(n == 2)
        {
            int left = start, right = size - 1;
            while(left < right)
            {
                int leftNum = nums[left], rightNum = nums[right];
                int sum = leftNum + rightNum;
                if(sum < target)
                {
                    while(left < right and leftNum == nums[left])   // remove duplicates
                        ++left;
                }
                else if(sum > target)
                {
                    while(left < right and rightNum == nums[right]) // remove duplicates
                        --right;
                }
                else
                {
                    res.push_back({leftNum, rightNum});
                    while(left < right and leftNum == nums[left])   // remove duplicates
                        ++left;
                    while(left < right and rightNum == nums[right]) // remove duplicates
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
                vector<vector<int>> subRes = nSum(nums, n - 1, i + 1, target - curNum);
                // (n - 1)Sum + current number nums[i] is nSum
                for(auto& subR : subRes)
                {
                    subR.push_back(curNum);
                    res.push_back(subR);
                }
                while(i < size and nums[i] == curNum) // remove duplicates & set i to the start of the next number
                    ++i;
            }
        }
        return res;
    }
};