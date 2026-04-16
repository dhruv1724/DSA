class Solution {
public:
    long long find(string &s, string &t, int i, int j, vector<vector<long long>>& dp){
        
        // agar pura t match ho gaya
        if(j == t.size()) return 1;

        // agar s khatam ho gaya
        if(i == s.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        long long include = 0, exclude = 0;

        if(s[i] == t[j]){
            include = find(s, t, i+1, j+1, dp);
        }

        exclude = find(s, t, i+1, j, dp);

        return dp[i][j] = include + exclude;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return find(s, t, 0, 0, dp);
    }
};