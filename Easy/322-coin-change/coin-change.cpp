class Solution {
public:
    int find(vector<int>&coins,int amount,int i,vector<vector<int>>&dp){
        if(amount<0){
            return INT_MAX; //yeh kbhi ans nhi ho skta
        }
        if(amount==0){
            return 0; //koi coin nhi chahiye
        }
        if(i==coins.size()-1){
            //idhar exclude krke hi pohochenge
            if(amount % coins[i]==0){
                return amount/coins[i];
            }
            return INT_MAX; 
        }
        //2 way-> ya toh include krliya //ya tohe exclude krke vaapis kbhi include nhi kra
        if(dp[i][amount]!=-1) return dp[i][amount];
        int way1=INT_MAX;
        if(amount>=coins[i]){
            //dp ki call tbhi jayegi when index is in bounds for amount
            way1=find(coins,amount-coins[i],i,dp)!=INT_MAX ? 1+find(coins,amount-coins[i],i,dp):INT_MAX;
        }
        int way2=find(coins,amount,i+1,dp);
        dp[i][amount]=min(way1,way2);
        return dp[i][amount];
    } 
    int findUsingTab(vector<int>&coins,int amount){
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,INT_MAX));
        //base case
        //last row mei jahan bhi amount coins[i] se divisible hoga
        int n=coins.size();
        for(int i=0;i<=amount;i++){
            if(i % coins[n-1]==0){
                dp[n-1][i]= i/coins[n-1];
            }
        }
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=amount;j++){
                int way1=INT_MAX;
                if(j>=coins[i]){
                    //dp ki call tbhi jayegi when index is in bounds for amount
                    way1=dp[i][j-coins[i]]!=INT_MAX ? 1+dp[i][j-coins[i]]:INT_MAX;
                }
                int way2=dp[i+1][j];
                dp[i][j]=min(way1,way2);
            }
        }
        return dp[0][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        //take or not take
        int i=0;
        sort(coins.begin(),coins.end());
        //vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=findUsingTab(coins,amount);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};