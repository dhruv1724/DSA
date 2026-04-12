class Solution {
public:
    void modify(int num,vector<bool>&Prime){
        int i=2;
        while(i*num<Prime.size()){
            Prime[i*num]=false;
            i++;
        }
        return ;
    }
    void createSieve(vector<bool>&Prime,int n) {
        //sieve of erosthyenes for 0 to n-1 index
        // saare prime marked initially
        //jb prime mile mark it 
        //if(n<=1) return 0;
        Prime[0]=false;
        Prime[1]=false;
        for(int i=0;i<Prime.size();i++){
            if(Prime[i]){
                //idhar hmesha humein exact prime hi milega
                //jo non prime true marked hai would be made false by previous encountered prime
                //jb prime marked hai
                modify(i,Prime);
            }
        }
        return ;
    }
    int toNonPrime(int num,vector<bool>&sieve){
        int ans=0;
        while(num<sieve.size() && sieve[num]!=false){
            num++;
            ans++;
        }
        return ans;
    }
    int toPrime(int num,vector<bool>&sieve){
        //non prime se prime mei krna hai
        int ans=0;
        while(num<sieve.size() && sieve[num]!=true){
            num++;
            ans++;
        }
        return ans;
    }
    int minOperations(vector<int>& nums) {
        //even index->prime
        //odd index->non prime
        int ops=0;
        //we will make a sieve of 1e5 +1
        vector<bool>sieve(1e5+20,true);
        createSieve(sieve,sieve.size());
        for(int i=0;i<nums.size();i++){
            if(i & 1){
                //odd index
                ops+=toNonPrime(nums[i],sieve);
            }else{
                //even index
                ops+=toPrime(nums[i],sieve);
            }
        }
        return ops;
    }
};