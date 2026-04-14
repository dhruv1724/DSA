class Solution {
public:
    int findUsingTab(vector<int>& nums1,vector<int>&nums2){
        //last index bharna hai 
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int n1=nums1.size();
        int n2=nums2.size();
        int maxi=0;
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int way1=0;
                int way2=0;
                if(nums1[i]==nums2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                    maxi=max(dp[i][j],maxi);
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return maxi;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=findUsingTab(nums1,nums2);
        return ans;
    }
};