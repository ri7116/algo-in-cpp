// 3 + 5 + 7 = 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= int(prices.size());
        vector<int> dpF(n);
        int minPrice=prices[0];
        for(int i=1;i<n;i++){
            dpF[i]=max(dpF[i-1],prices[i]-minPrice);
            minPrice=min(minPrice, prices[i]);//저점의 위치
        }
        //앞에서 주식을 사고 판날 최대 이익
        vector<int> dpB(n);
        int maxPrice=prices[n-1];
        for(int i=n-2;i>=0;i--){
            dpB[i]=max(dpB[i+1],maxPrice-prices[i]);//더 이득이 커지나?
            maxPrice= max(maxPrice, prices[i]);//고점의 위치
        }
        //먼저 팔고 나중에 산다는 논리
        int res=dpF[n-1]; //1개 선택 
        for(int i=1;i+1<n-1;i++){
            res=max(res,dpF[i]+dpB[i+1]);
        }
        return res;
    }
};