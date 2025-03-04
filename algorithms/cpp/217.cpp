class Solution {
    public:
        /** 
            Hash Table, Array
            
            Removing duplicates is a classic use case for hash sets, as they allow you to quickly check if an element is already present in the set.
            We can insert each element of the array into a hash set one by one, and if we find an element that is already in the set, we immediately return true.

            time O(n)
            space O(n)
        */
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> uset;
            for(auto &num : nums)
            {
                //// if the element already exists, we find a duplicate. return true
                if(uset.contains(num))
                    return true;
                
                //// insert the element into the hash set
                uset.insert(num);
            }
            return false;
        }
};