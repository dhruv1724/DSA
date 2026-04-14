class Solution {
public:
    int scoreOfString(string s) {
        int i=0;
        int j=1;
        int sum=0;
        while(j!=s.size()){
            int a=s[i]-'a';
            int b=s[j]-'a';
            sum+=abs(a-b);
            i++;
            j++;
        }
        return sum;
    }
};