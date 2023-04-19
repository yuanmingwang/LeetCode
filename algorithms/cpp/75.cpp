class Solution {
public:
    /** 
        Two Pointers
        
        This is a Dutch National Flag problem / 3-Way QuickSort
        We use 3 pointers to mark the pos of red, white and blue
        At any point, every element before left is 0, every element after right is 2, every element in between are either 0, 1 or 2 i.e. unprocessed.
        We'll use mid pointer to traverse and check the array elements i.e. while(mid <= right). Three cases are possible:
            1. nums[mid] == 0 In this case swap(nums[left], nums[mid]) and increment both left and mid pointer i.e. left++ mid++
            2. nums[mid] == 1 In this case mid++
            3. nums[mid] == 2 In this case swap(nums[mid], nums[right]) and decrement right pointer i.e. right--

        time O(N)
        space O(1)
    */
    void sortColors(vector<int>& nums) {
        int left = 0;   // red
        int mid = 0;    // white
        int right = nums.size() - 1;    // blue
        
        // we use mid to traverse nums
        while(mid <= right)
        {
            // 1. red
            if(nums[mid] == 0)
            {
                swap(nums[left], nums[mid]);
                ++left;
                ++mid;
            }
            // 2. white
            else if(nums[mid] == 1)
            {
                ++mid;
            }
            // 3. blue
            else
            {
                swap(nums[mid], nums[right]);
                --right;
            }
        }
    }
};