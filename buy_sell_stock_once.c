/* Say you have an array for which the ith element 
 * is the price of a given stock on day i. If you 
 * were only permitted to complete at most one 
 * transaction (ie, buy one and sell one share 
 * of the stock), design an algorithm to find the 
 * maximum profit.
 */

int maxProfit(int* prices, int pricesSize) {

    int i = 0;
    int profit = 0;
    int prev = 0;
    int min = prices[0];
    
    if (pricesSize == 0 || pricesSize == 1)
        return 0;
        
    while ( i != (pricesSize-1)) {
        
        if (min < prices[i+1]) {
            profit = prices[i+1] - min;
            if (prev > profit) {
                profit  = prev;
            }
            printf("profit %d\n", profit);
        } else {
            min = prices[i+1];
        }    
        i++;
        prev = profit;
    }
    
    return profit;
}
