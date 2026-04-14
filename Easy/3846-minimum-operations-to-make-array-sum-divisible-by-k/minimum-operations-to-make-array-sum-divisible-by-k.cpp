class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //sum divisible by k
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum<k) return sum;
        int rem=sum%k;
        return rem;
    }
};