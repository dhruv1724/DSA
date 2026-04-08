class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //child will be content if s[j]>=g[i]
        //for every child find a greater cookie
        //for every child find a greater or equal unique element in s
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        vector<bool>given(s.size(),false);
        int j=0;
        for(int i=0;i<g.size();i++){
            while(j<s.size() && s[j]<g[i]){
                j++;
            }
            //yahan pr ya toh j out of bounds ya condition meet ho gyi

            if(j==s.size()){
                break;
            }
            if(s[j]>=g[i]){
                j++;
                ans++;
                continue;
            }
          
        }
        return ans;
    }
};