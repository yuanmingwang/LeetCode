class Solution {
public:
    /** 
        dp, priority_queue.
        similar to 264. Ugly Number II https://leetcode.com/problems/ugly-number-ii/description/
        
        def: 
            list of ugly numbers, in ascending order
        stf:
            1. find curMin 
            2. add curMin to dp
            3. update pointer, value of product of 2, 3, 5 if curMin is a product of any one of them
        bc:
            dp[1] = 1, 1 is the first ugly number

        time O(nlogm) where n = n, m = primes.size()
        space O(n + m)
    */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> dp(n, 1);
        // store {product, prime, idnex} of all primes in primes. product = value of product, index = pointer position
        priority_queue<vector<long>, vector<vector<long>>, greater<vector<long>>> pq;
        int prime, product, index;
        //// init pq with {product, prime, idnex}
        for(auto& p : primes)
        {
            pq.push({1, p, 0});
        }
            
        //// bc
        dp[0] = 1;
        //// dp
        int i = 1;
        while(i < n)
        {
            //// find curMin
            vector<long> curMin = pq.top();
            product = curMin[0];
            prime = curMin[1];
            index = curMin[2];
            pq.pop();
            //// add curMin product to dp only if it is not a duplicate
            if(dp[i - 1] != product)
            {
                dp[i] = product;
                ++i;
            }
            //// update pointer, product if curMin is a product of any one of them
            pq.push({dp[index] * prime, prime, index + 1});

            // cout<<"i: "<<i<<", prime: "<<prime<<", product: "<<product<<", index: "<<index<<", dp[index]: "<<dp[index]<<endl;
        }
        // for(auto& i : dp)
        //     cout<<i<<" ";

        return dp[n - 1];
    }

    //// if we put product as the first argument like this {product, prime, idnex}, we can use greater<vector<int>> instead of this customer comparator
    //// greater<vector<int>> will first compare the 1st argument in vector
    //// 
    // struct comp
    // {
    //     bool operator()(vector<int>& a, vector<int>& b)
    //     {
    //         return a[0] > b[0]; // return the one with smaller product
    //     }
    // };
};
