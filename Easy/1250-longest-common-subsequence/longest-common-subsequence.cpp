class Solution {
public:
    int find(int i,int j,string text1,string text2,vector<vector<int>>&dp){
        if(i==text1.size() || j==text2.size()){
            return 0;
        }
        int way1=0;
        int way2=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            way1=1+find(i+1,j+1,text1,text2,dp);
        }else{
            way2=max(find(i,j+1,text1,text2,dp),find(i+1,j,text1,text2,dp));
        }
        return dp[i][j]=max(way1,way2);
    }
    int findUsingTab(string text1,string text2){
        //last index bharna hai 
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        int n1=text1.size();
        int n2=text2.size();
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int way1=0;
                int way2=0;
                if(text1[i]==text2[j]){
                    way1=1+dp[i+1][j+1];
                }else{
                    way2=max(dp[i][j+1],dp[i+1][j]);
                }
                dp[i][j]=max(way1,way2);
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        // vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        int ans=findUsingTab(text1,text2);
        return ans;
    }
};