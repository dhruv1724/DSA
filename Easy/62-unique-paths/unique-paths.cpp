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
    int findUsingTab(int m,int n){
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=1;
        //LAST ROW
        for(int i=0;i<n;i++){
            dp[m-1][i]=1;
            //1 hi way hai right jaake
        }
        //LAST COLUMN
        for(int i=0;i<m;i++){
            dp[i][n-1]=1;
            //1 hi way hai down jaake
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int way1=dp[i+1][j]; //moving down
                int way2=dp[i][j+1]; //moving right
                dp[i][j]= way1+way2;;
            }
        }
        return dp[0][0];
    }
    //for SO ans depends on down row ka j and current row ka next element
    int solveUsingSO(int m,int n){
        vector<int>currentRow(n,-1);
        vector<int>nextRow(n,-1);
        
        //LAST ROW
        for(int i=0;i<n;i++){
            currentRow[i]=1;
            //1 hi way hai right jaake
        }
        //LAST COLUMN
        nextRow[n-1]=1;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int way1=currentRow[j]; //moving down
                int way2=nextRow[j+1]; //moving right
                nextRow[j]= way1+way2;;
            }
            currentRow=nextRow;
        }
        return currentRow[0];
    }
    int uniquePaths(int m, int n) {
        //make relation based on index 
        //do all stuffs
        //find the best way/all possible ways
        // int i=0;
        // int j=0;
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=solveUsingSO(m,n);
        return ans;
    }
};