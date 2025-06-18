class NumArray {
public:
    /** 
        Array, Prefix Sum

        Intuition: 
            The core idea is that we construct a preSum array. preSum[i] records the sum of nums[0..i].

            If we want to find the sum of all the elements in the index interval [1, 4], I can get it by preSum[4] - preSum[0].

            Hence, the sumRange function only needs to be subtracted once, avoiding the need for loop call every time, and the worst time complexity is constant
        
        time O(N)
        space O(N)
    **/

    vector<int> preSum;
    //// construct the preSum array
    NumArray(vector<int>& nums) {
        int size = nums.size();
        preSum.resize(size);
        //// bc. preSum[0] = 0 so that it is easy for us to calculate preSum[i] - preSum[0]
        preSum[0] = nums[0];

        //// construct preSum
        for(int i = 1; i < size; ++i)
        {
            preSum[i] = preSum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? preSum[right] : preSum[right] - preSum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */