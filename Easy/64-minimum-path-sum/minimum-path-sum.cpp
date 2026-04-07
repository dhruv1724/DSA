class Solution {
public:
    int find(vector<vector<int>> &grid,int i,int j,vector<vector<int>>&dp){
        if(i==grid.size() || j==grid[0].size()){
            return INT_MAX;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            //last box pr hai  hum
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int way1=find(grid,i+1,j,dp)==INT_MAX? INT_MAX : grid[i][j]+find(grid,i+1,j,dp); //down
        int way2=find(grid,i,j+1,dp)==INT_MAX? INT_MAX : grid[i][j]+find(grid,i,j+1,dp); //right
        return min(way1,way2);    
    }
    int findUsingTab(vector<vector<int>> &grid){
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,INT_MAX));
        dp[grid.size()-1][grid[0].size()-1]=grid[grid.size()-1][grid[0].size()-1];
        int r=grid.size();
        int c=grid[0].size();
        // last row
        for(int j = c-2; j >= 0; j--){
            dp[r-1][j] = grid[r-1][j] + dp[r-1][j+1];
        }

        // last column
        for(int i = r-2; i >= 0; i--){
            dp[i][c-1] = grid[i][c-1] + dp[i+1][c-1];
        }
        for(int i=r-2;i>=0;i--){
            for(int j=c-2;j>=0;j--){
                int way1=dp[i+1][j]==INT_MAX? INT_MAX : grid[i][j]+dp[i+1][j]; //down
                int way2=dp[i][j+1]==INT_MAX? INT_MAX : grid[i][j]+dp[i][j+1]; //right
                dp[i][j]=min(way1,way2);
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // int i=0;
        // int j=0;
        // vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=findUsingTab(grid);
        return ans;
    }
};