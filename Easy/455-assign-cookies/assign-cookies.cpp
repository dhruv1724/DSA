class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //maximum content will be when child receives cookie just equal or nearest to greed factor
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //ek loop chlao hr child ke liye
        //agar usse bda mil gya add it
        //agar nhi mila->baaki ke liye bhi nhi milega
        int j=0;
        int ans=0;
        for(int i=0;i<g.size();i++){
            int greed=g[i];
            while(j<s.size() && greed>s[j]){
                j++;
            }
            if(j==s.size()){
                //nhi mila iske liye cookie 
                break;
            }
            if(s[j]>= greed){
                ans+=1; //1 child satisfied
                j++;//agle child ke lie agle j se
            }
        }
        return ans;
    }
};