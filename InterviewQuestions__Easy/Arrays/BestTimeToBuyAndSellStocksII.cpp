class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size(), ans = 0;
        
        // I bought on 1st day
        int buyPrice = prices[0];
        
        for(int i=1; i<len; ++i) {
            if(prices[i] > buyPrice) {
                // Add the revenue
                ans += (prices[i] - buyPrice);
                // Buy again today
                buyPrice = prices[i];
            }
            else {
                // Unbuy and buy again at lower price
                buyPrice = prices[i];
            }
        }
        return ans;
    }
};