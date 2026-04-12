class Solution {
public:
    int find(vector<int>&nums,int i,int target,vector<vector<int>>&dp,int total){
        if(target + total < 0 || target + total > 2*total) return 0;

        
        if(i==nums.size()){
            if(target==0) return 1;
            return 0;
        }
        if(target+total>=0 && dp[i][target+total]!=-1) return dp[i][target+total];
        int way1=find(nums,i+1,target-nums[i],dp,total);
        int way2=find(nums,i+1,target+nums[i],dp,total);
        return dp[i][target+total]=way1+way2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int i=0;
        int total=0;
        for(auto i:nums){
            total+=i;
        }
        //note target total can become negative also
        //so we can get negative index which will give runtime error
        vector<vector<int>>dp(nums.size(),vector<int>(2*total+1,-1));
        int ans=find(nums,i,target,dp,total);
        return ans;
    }
};