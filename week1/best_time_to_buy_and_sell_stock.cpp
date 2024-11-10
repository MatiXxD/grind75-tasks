int maxProfit(std::vector<int> &prices) {
  int profit = 0, minInd = 0;
  for (int i = 0; i != prices.size(); ++i) {
    if (prices[i] < prices[minInd]) {
      minInd = i;
    }
    profit = std::max(profit, prices[i] - prices[minInd]);
  }
  return profit;
}
