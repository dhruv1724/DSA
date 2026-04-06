class Solution {
public:
    int find(int rows,int cols,int i,int j,vector<vector<int>>&dp){
        if(i==rows-1 && j==cols-1){
            return 1;
        }
        if(i==rows || j==cols){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int way1=find(rows,cols,i+1,j,dp); //moving down
        int way2=find(rows,cols,i,j+1,dp); //moving right
        dp[i][j]= way1+way2;;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        //make relation based on index 
        //do all stuffs
        //find the best way/all possible ways
        int i=0;
        int j=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=find(m,n,i,j,dp);
        return ans;
    }
};