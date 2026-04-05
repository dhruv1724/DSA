class Solution {
public:
    int find(vector<int> &nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
            //for out of bounds
        }else{
            //i in bounds
            if(dp[i]!=-1) return dp[i];           
            int include=nums[i]+find(nums,i+2,dp);
            int exclude=find(nums,i+1,dp);
            dp[i]=max(include,exclude);
            return dp[i];
        }
    }
    int rob(vector<int>& nums) {
        //1 se lekr n
        vector<int>dp(nums.size()+1,-1);
        int ans1=find(nums,1,dp);
        //0 se lekr n-1       
        nums.pop_back();
        vector<int>dp1(nums.size()+1,-1);
        int ans2=nums[0]+find(nums,2,dp1);
        return max(ans1,ans2);
    }
};