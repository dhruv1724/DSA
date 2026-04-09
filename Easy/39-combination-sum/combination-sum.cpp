class Solution {
public:
    void find(vector<int>&candidates,int i,int target,vector<vector<int>>&ans,vector<int>&temp){
        if(i==candidates.size()){
            return ;
        }
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        if(target<0){
            return;
        }
        temp.push_back(candidates[i]);
        //find(candidates,i+1,target-candidates[i],ans,temp); //include
        find(candidates,i,target-candidates[i],ans,temp); //include 1
        temp.pop_back();
        find(candidates,i+1,target,ans,temp);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //include and exclude 
        //include mei bhi two cases include krke aage move kr gye ya toh vhi pr rhein
        int i=0;
        vector<vector<int>>ans;
        vector<int>temp;
        find(candidates,i,target,ans,temp);
        return ans;
    }
};