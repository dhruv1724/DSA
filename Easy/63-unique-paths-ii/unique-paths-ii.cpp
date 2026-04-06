class Solution {
public:
    int find(vector<vector<int>> &matrix,int i,int j,vector<vector<int>>&dp){
        if(i==matrix.size()-1 && j==matrix[0].size()-1){
            return 1;
        }
        if(i==matrix.size() || j==matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(matrix[i][j]==0){
            int way1=find(matrix,i+1,j,dp); //down path
            int way2=find(matrix,i,j+1,dp); //right path
            dp[i][j]=way1+way2;
            return dp[i][j];
        }else{
            return 0;
        }
    }   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r=obstacleGrid.size();
        int c=obstacleGrid[0].size();
        if(obstacleGrid[r-1][c-1]==1) return 0;
        int i=0;
        int j=0;
        vector<vector<int>>dp(r,vector<int>(c,-1));
        int ans=find(obstacleGrid,i,j,dp);
        return ans;
    }
};