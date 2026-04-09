class Solution {
public:
    // bool find(vector<int>&nums,int& sum1,int& sum2,int i){
    //     if(i==nums.size()){
    //         if(sum1==sum2){
    //             return true;
    //         }else{
    //             return false;
    //         }
    //     }
    //     sum1+=nums[i];
    //     bool ans1=find(nums,sum1,sum2,i+1);
    //     sum1-=nums[i];
    //     sum2+=nums[i];
    //     bool ans2=find(nums,sum1,sum2,i+1);
    //     sum2-=nums[i];
    //     return ans1 || ans2;
    // }
    //partition equals subset sum means we can find a subset with sum being half of total sum
    int find(vector<int> &nums,int target,int i,vector<vector<int>> &dp){
        if(i==nums.size()){
            return 0;
        }
        if(nums[i]==target){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int include=find(nums,target-nums[i],i+1,dp);
        int exclude=find(nums,target,i+1,dp);
        dp[i][target]=include || exclude;
        return dp[i][target];
    }
    bool canPartition(vector<int>& nums) {
        int i=0;
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum & 1) return false;
        int target=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        int ans=find(nums,target,i,dp);
        return ans==1 ? true :false;
    }
};