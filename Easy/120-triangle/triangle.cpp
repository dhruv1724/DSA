class Solution {
public:
    int find(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>&dp){
        //cases
        //i exceeds the range
        if(i==triangle.size()){
            return 0;
        }
        //j not in range
        if(j==triangle[i].size()){
            //jis row mei hai 
            return INT_MAX;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int way1=find(triangle,i+1,j,dp);
        int way2=find(triangle,i+1,j+1,dp);
        return dp[i][j]=triangle[i][j] + min(way1,way2);
    }
    int findUsingTab(vector<vector<int>> &triangle){
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),INT_MAX));
        //base case
        //hr index represents 0,0 se uss index ka path
        //and it depends on dp of next row
        //so make the dp of last row index = uss ki triangle ki value
        //then agar j+1 bahar jaata hai make them return INT_MAX there
        for(int i=0;i<triangle[triangle.size()-1].size();i++){
            dp[triangle.size()-1][i]= triangle[triangle.size()-1][i];
        }
        for(int i=triangle.size()-2;i>=0;i--){
            int c=triangle[i].size();
            for(int j=0;j<c;j++){
                int way1=dp[i+1][j]; 
                int way2=dp[i+1][j+1]; //j+1 ki value INT_MAX ho jayegi agar voh agli row ke size se bahar gya
                dp[i][j]=triangle[i][j] + min(way1,way2);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int i=0;
        // int j=0;
        // vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        int ans=findUsingTab(triangle);
        return ans;
    }
};