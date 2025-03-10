class Solution {
    public:
        /** 
            Array, Binary Search
    
            standard binary search framework, search for the
            index of the target element, return -1 if it does not
    
            1. Why is the condition in the while loop <= instead of <?
            Answer: Because the initialization of right is assigned as nums.length - 1, which is the index of the last element, not nums.length.
                    In our algorithm, we use [left, right] which is closed interval on both ends. This interval is essentially the search range for each iteration.
    
            2. Why left = mid + 1 and right = mid - 1?
            Answer: in this algorithm, the search interval is closed on both ends, i.e., [left, right]. 
                    So, when we find that the index mid is not the target we are looking for, we should search in the interval [left, mid-1] or [mid+1, right], right? **Because mid` has already been searched, it should be removed from the search interval.**
    
            time O(logn)
            space O(1)
        */
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
    
            while(left <= right)
            {
                // same result as (left + right) / 2, but effectively prevents overflow
                int mid = left + (right - left) / 2;
                if(nums[mid] == target)
                    return mid;
                // mid smaller than the target, the target is on the right side, so move the left pointer
                else if(nums[mid] < target)
                    left = mid + 1;
                // mid larger than the target, the target is on the left side, so move the right pointer
                else if(nums[mid] > target)
                    right = mid - 1;
            }
            return -1;
        }
    };