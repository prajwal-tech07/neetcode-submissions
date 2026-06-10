class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        int right=1;
        int mprofit=0;
        while(right<prices.size()){
            if(prices[right]>prices[left]){
                int profit=prices[right]-prices[left];
                mprofit=max(mprofit,profit);
            }else{
                left=right;
            }
            right++;
        }
        return mprofit;
    }
};
