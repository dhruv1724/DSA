class Solution {
public:
    int find(vector<int>& days,vector<int>&costs,int i,vector<int>&dp){
        if(i==days.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int way1=costs[0]+find(days,costs,i+1,dp);
        //ab check days[i] se 6 day aur kis index tk bdaa hai
        int i2=i;
        while(i2<days.size() && days[i2]<=days[i]+6){
            i2++;
        }
        //ab days[i2] pr jo din hai voh travel nhi hua hai
        int way2=costs[1]+find(days,costs,i2,dp);
        int i3=i;
        while(i3<days.size() && days[i3]<=days[i]+29){
            i3++;
        }
        int way3=costs[2]+find(days,costs,i3,dp);
        dp[i]=min(way1,min(way2,way3));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i=0;
        //we have to cover every day
        //goal->travel on all days from given cost plan
        vector<int>dp(days.size(),-1);
        int cost=find(days,costs,i,dp);
        return cost;
    }
};