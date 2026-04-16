class Solution {
public:
    int find(string &word1,string &word2,int i,int j,vector<vector<int>>&dp){
        if(i==word1.size() && j==word2.size()){
            //no deletion both are same now
            return 0;
        }else if(i==word1.size()){
            //word2 ke baaki delete kro
            return word2.size()-j;
        }else if(j==word2.size()){
            //word1 ke baaki delete kro
            return word1.size()-i;
        }else{
            if(dp[i][j]!=-1) return dp[i][j];
            if(word1[i]==word2[j]){
                return dp[i][j]=find(word1,word2,i+1,j+1,dp);
            }else{
                return dp[i][j]=1 + min(find(word1,word2,i+1,j,dp),find(word1,word2,i,j+1,dp));
            }
        }
    }
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        int ans=find(word1,word2,i,j,dp);
        return ans;
    }
};