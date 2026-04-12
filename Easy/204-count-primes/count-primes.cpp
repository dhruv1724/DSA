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
    int countPrimes(int n) {
        //sieve of erosthyenes for 0 to n-1 index
        // saare prime marked initially
        //jb prime mile mark it 
        if(n<=1) return 0;
        vector<bool>Prime(n,true);
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
        int ans=0;
        for(int i=0;i<Prime.size();i++){
            if(Prime[i]) ++ans;
        }
        return ans;
    }
};