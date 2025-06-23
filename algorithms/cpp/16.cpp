class Solution {
public:
    /** 16. 3Sum Closest
        Two Pointers

        time O(N^2)
        space O(1)
    */
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int min_diff = INT_MAX; // diff = target - sum
        int res = nums[0] + nums[1] + nums[2];
        
        //// fix a number and find the other two
        for(int i = 0; i < size; ++i)
        {
            int left = i + 1;   // i + 1 because i is fixed as the first number
            int right = size - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                //// update res and min_diff
                int diff = abs(target - sum);
                if(diff < min_diff)
                {
                    min_diff = diff;
                    res = sum;
                }
                //// move pointer
                if(sum < target)
                    ++left;
                else if(sum > target)
                    -- right;
                else    // sum = target, we can return res directly
                    return res;
            }
        }
        return res;
    }
};