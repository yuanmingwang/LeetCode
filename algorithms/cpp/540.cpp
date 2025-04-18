class Solution {
    public:
    //// 540. Single Element in a Sorted Array
    /** 
        
        Array, XOR

        Approach #1: XOR

        time O(n)
        space O(1)
    */
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        // xor-ing all elements of array
        for(auto& num : nums)
            res = res ^ num;
        return res;
    }


    /** 2.---------------------------------------------------------------------------------------------------------------------------------------- **/
    //// 540. Single Element in a Sorted Array
    /** 
        Array, Binary Search

        Approach #2: Binary Search
            We always have an odd number of arrays because one element appears once and the rest appear twice.
            If we remove a pair of elements from the center. There will be a left subarray and a right subarray left.
            As with the original array, the number of elements in a subarray that contains a single element must be odd, 
                and the number of elements in a subarray that does not contain a single element must be even.
            ex: [1,1,4,4,5,5,6,6,8,9,9] -> [1,1,4,4] and [6,6,8,9,9] after removing [5,5]

            1. nums[mid] == nums[mid+1]:
                Left Half Length = Right Half Length = Even : The answer lies in the right half.
                Left Half Length = Right Half Length = Odd : The answer lies in the left half.
            2. nums[mid] == nums[mid-1]:
                Left Half Length = Right Half Length = Even : The answer lies in the left half.
                Left Half Length = Right Half Length = Odd : The answer lies in right half.
            3. nums[mid] != nums[mid-1] != nums[mid+1]
                nums[mid] itself is the required element occuring once since it doesnt match with its neighbours


        time O(logn)
        space O(1)
    */
   int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        // check length of left half is odd or even. if left half is even, right half must be odd
        bool isLeftEven = (mid - left) % 2 == 0;
        //// case 1.
        if(mid + 1 < nums.size() and nums[mid] == nums[mid + 1])
        {
            if(isLeftEven)
                left = mid + 2;
            else
                right = mid - 1;
        }
        //// case 2.
        else if(mid != 0 and nums[mid] == nums[mid - 1])
        {
            if(isLeftEven)
                right = mid -2;
            else
                left = mid + 1;
        }
        //// case 3.
        else
        {
            return nums[mid];
        }
    }
    //// wont be reached since we will always find required element inside loop
    return -1;
}
};