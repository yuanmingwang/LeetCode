class Solution {
    public:
        /** 
            Array, Simulation
            One Pass
    
            We can break down the entire problem into two cases:
                1. For i <= k, tickets[i] contributes min(tickets[k], tickets[i]) steps.
                2. For i > k,  tickets[i] contributes min(tickets[k] - 1, tickets[i]) steps.
    
            1. This is because we want to ensure that the kth person gets the tickets they need, and people before the kth person will only have the opportunity to buy up to tickets[k] tickets.    
            2. People after k in line will have fewer opportunities to buy tickets than person k does. If they need fewer than tickets[k] tickets, they will be able to purchase them all. Otherwise, they will purchase tickets[k] - 1 tickets.
            
            time O(n)
            space O(1)
        */
        int timeRequiredToBuy(vector<int>& tickets, int k) {
            int res = 0;
    
            for(int i = 0; i < tickets.size(); ++i)
            {
                if(i <= k)  // case 1
                    res += min(tickets[i], tickets[k]);
                else    // case 2
                    res += min(tickets[i], tickets[k] - 1);
            }
    
            return res;
        }
    };