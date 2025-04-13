class Solution {
    public:
        /** 
            Array, Two Pointers
    
            Initialize the two pointers at the end of the array and and merge from back to front.
            Even if we overwrite elements in nums1, those elements would have already been used and won't affect the correctness of the answer.
    
            time O(m + n)
            space O(1)
        */
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            // p1 and p2 point to the last element of nums1 and nums2
            int p1 = m - 1, p2 = n - 1;
            // p handle the result array
            int p = m + n - 1;
            // generate the result array from back to front, similar to the logic of 21.Merge Two Sorted Lists.
            while(p1 >= 0 and p2 >= 0)
            {
                if(nums1[p1] > nums2[p2])
                {
                    nums1[p] = nums1[p1];
                    --p1;
                }
                else
                {
                    nums1[p] = nums2[p2];
                    --p2;
                }
                --p;
            }
            // It's possible that one of the arrays has reached the end of its pointer, while the other hasn't.
            // Since we're putting elements into nums1, we only need to consider whether nums2 has elements left.
            while(p2 >= 0)
            {
                nums1[p] = nums2[p2];
                --p2;
                --p;
            }
        }
    };