class Solution {
    public:
        /** 
            Hash Table
            
            For issues related to counting elements, we typically use key-value pairs to store the relationship between elements and their occurrence counts.
            This involves using a data structure like a hash table.
            
            time O(n)
            space O(n)
        */
        int singleNumber(vector<int>& nums) {
            // umap.fisrt = num, umap.second = frequency of num that appears in nums
            unordered_map<int,int> umap;
            
            //// traverse the array, count the frequency of each number
            for(auto &num : nums)
                ++umap[num];
            
            //// find the number that only appears once
            for(auto &element : umap)
            {
                if(element.second == 1)
                    return element.first;
            }
            return -1;
        }


        // 2. -------------------------------------------------------------------------------------------------------------- 
        /** 
            Bit Manipulation
            We us XOR Gate. The output is true only if both the inputs are of opposite kind. That is:
                A B Res
                0 0 0
                0 1 1
                1 0 1
                1 1 0

            If we do "a^b" (applying the XOR gate on the 2 numbers in a bitwise fashion on each of the corresponding bits of the numbers), we have:
                A^0 = A
                A^A = 0
                A^B^A = B
                a ^ b = b ^ a -> XOR is commutative, the order doesn't matter
                (A^A^B) = (B^A^A) = (A^B^A) = B -> a number XOR by another number twice makes no change on original number
                A^A^A......... (even times) = 0 and A^A^A........(odd times) = A

            Hence, we can use XOR to solve this problem in o(n) time and o(1) space by:
                1. Traverse the array and take the Bitwise XOR of each element with res(default = 0).
                2. Return the res.
            
            time O(n)
            space O(1)
        */
        int singleNumber(vector<int>& nums) {
        int res = 0;
        
        //// Traverse the array and take the Bitwise XOR of each element.
        for(auto &num : nums)
            res = res ^ num;
        
        //// The elements with frequency = 2 will result in 0. 
        //// And then the only element with frequency = 1 will generate the res since 0 ^ x = x.
        return res;
    }
};