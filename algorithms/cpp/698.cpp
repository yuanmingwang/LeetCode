//// This solution will get TLE because it does not use memo to prune the used cased
//// we can also sort the nums in decending order to prune more leaf but it will still get TLE
class Solution {
public:
    /** 
        Backtracking, DFS
        logic: we take the view of subSet bucket because if we take the view of nums, we will have a complexity of n^k
        for each subSet bucket in k:
            for each num in nums:
                determine if we want to put num into subSet
                if the current subSet bucket is full (value = target), we go for the next subSet bucket
        we will keep doing it until we fill up all subSet bucket

        time O(2^N * N)
        space O(N)
    */
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //// bc & calculate target
        if(nums.size() < k)
            return false;
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum % k != 0)
            return false;
        int target = sum / k;

        vector<bool> used(nums.size(), false);
        return backtrack(nums, k, target, used, 0, 0);
    }

    // target: sum of nums / k, the target we want to have for each subSet bucket
    // used: used[i] means we have already used nums[i] in other subSet
    // start: start of this recursion
    // subSetSum: sum of the current subSet bucket
    bool backtrack(vector<int>& nums, int k, int target, vector<bool>& used, int start, int subSetSum)
    {
        //// bc
        // All subSet buckets are filled, and all nums must be used up because target = sum / k
        if(k == 0)
            return true;
        // When the current subSet bucket is filled, recursively fill the next subSet bucket. note we start from nums[0]
        if(target == subSetSum)
            return backtrack(nums, k - 1, target, used, 0, 0);
            
        
        //// find valid nums[i] to fill the current subSet bucket starting from nums[start]
        for(int i = start; i < nums.size(); ++i)
        {
            //// preorder edge
            //// pruning
            // nums[i] is used in other subSet bucket
            if(used[i])
                continue;
            // nums[i] can't fit in the current subSet bucket
            if(subSetSum + nums[i] > target)
                continue;
            //// make selection
            subSetSum += nums[i];
            used[i] = true;
            
            //// traverse
            // Recursively find the next number in nums that can fit into the current subSet bucket
            if(backtrack(nums, k, target, used, i + 1, subSetSum))  // find a solution, return true directly
                return true;

            //// postorder edge, revoke selection
            subSetSum -= nums[i];
            used[i] = false;
        }
        //// search over all numbers in nums but can not fill the current bucket
        return false;
    }
};

// --------------------------------------------------------------------
// --------------------------------------------------------------------

class Solution {
public:
    /** 
        Backtracking, DFS, Bitmask
        logic: we take the view of subSet bucket because if we take the view of nums, we will have a complexity of n^k
        for each subSet bucket in k:
            for each num in nums:
                determine if we want to put num into subSet
                if the current subSet bucket is full (value = target), we go for the next subSet bucket
        we will keep doing it until we fill up all subSet bucket

        use bitmask(int used in the code) to prune
        For example nums = [2,1,4,3,5,6,2], mask = "1100101" , then that means we have already chosen 2,1,5,2

        time O(2^N * N)
        space O(N)
    */
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //// bc & calculate target
        if(nums.size() < k)
            return false;
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum % k != 0)
            return false;
        int target = sum / k;

        dp = vector<int>(1 << 16, -1);  // shift 16 because nums.length <= 16. init dp to -1

        int used = 0;   // bitmask
        return backtrack(nums, k, target, used, 0, 0);
    }

    // dp[i] = -1 : not calculated yet
    // dp[i] = 0 : false
    // dp[i] = 1: true
    vector<int> dp;

    // target: sum of nums / k, the target we want to have for each subSet bucket
    // used: bitmask, used[i] means we have already used nums[i] in other subSet
    // start: start of this recursion
    // subSetSum: sum of the current subSet bucket
    bool backtrack(vector<int>& nums, int k, int target, int used, int start, int subSetSum)
    {
        //// bc
        // All subSet buckets are filled, and all nums must be used up because target = sum / k
        if(k == 0)
            return true;
        // we have already calculated this situation
        if(dp[used] != -1)
            return dp[used] == 1 ? true : false;
        // When the current subSet bucket is filled, recursively fill the next subSet bucket. note we start from nums[0]
        if(target == subSetSum)
        {
            bool res = backtrack(nums, k - 1, target, used, 0, 0);
            dp[used] = res ? 1 : 0;
            return res;
        }
        
        //// find valid nums[i] to fill the current subSet bucket starting from nums[start]
        for(int i = start; i < nums.size(); ++i)
        {
            //// preorder edge
            //// pruning
            // nums[i] is used in other subSet bucket
            if((used >> i) & 1 == 1)    // Determine whether the i-th bit of used is 1
                continue;
            // nums[i] can't fit in the current subSet bucket
            if(subSetSum + nums[i] > target)
                continue;
            //// make selection
            subSetSum += nums[i];
            used = used | 1 << i;   // Set i-th pos of used to 1
            
            //// traverse
            // Recursively find the next number in nums that can fit into the current subSet bucket
            if(backtrack(nums, k, target, used, i + 1, subSetSum))  // find a solution, return true directly
                return true;

            //// postorder edge, revoke selection
            subSetSum -= nums[i];
            used = used ^ 1 << i;   // Restore the i-th bit to 0 using the XOR operation
        }
        //// search over all numbers in nums but can not fill the current bucket
        return false;
    }
};