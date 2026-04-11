class Solution {
public:
    int find(vector<int>&nums,int target,int sum,int i){
        if(i==nums.size()){
            if(target==sum) return 1;
            return 0;
        }
        int way1= find(nums,target,sum-nums[i],i+1);
        int way2=find(nums,target,sum+nums[i],i+1);
        return way1+way2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int i=0;
        int ans=find(nums,target,sum,i);
        return ans;
    }
};