class Solution {
    public:
        /** 
            Array, Hash Table, Sliding Window
    
            time O(n)
            space O(n)
        */
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            // k = num in nums, v = indices of the num's most recent occurrence 
            unordered_map<int, int> window;
    
            for(int i = 0; i < nums.size(); ++i)
            {
                int i_curr = nums[i];
                //// if I have already seen this number, check for condition abs(i - j) <= k
                if(window.contains(i_curr))
                {
                    if(i - window[i_curr] <= k)
                        return true;
                }
                //// if I have not seen this number before, update the position of i_curr
                window[i_curr] = i;
            }
            //// if we don't find a pair to satisfy the condition after the complete traversal, return false
            return false;
        }
    };