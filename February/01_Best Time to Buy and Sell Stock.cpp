class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0 ;
        int minPrice = INT_MAX;

        for (int price : prices) {

            minPrice = min({minPrice , price});

            int currProfit =  price - minPrice ;

            maxProfit = max(maxProfit , currProfit);
        }

        return maxProfit ;
    }
};