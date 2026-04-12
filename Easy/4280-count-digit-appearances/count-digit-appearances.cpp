class Solution {
public:
    int check(int num,int digit){
        int ans=0;
        while(num){
            int n=num%10;
            if(n==digit){
                ans+=1;
            }
            num=num/10;
        }
        return ans;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(auto i:nums){
            ans+=check(i,digit);
        }
        return ans;
    }
};