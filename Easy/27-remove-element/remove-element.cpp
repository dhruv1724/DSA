class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //jb bhi val mile shift it right
        stack<int>s;
        for(auto i:nums){
            if(i==val){
                continue;
            }else{
                s.push(i);
            }
        }
        nums.clear();
        while(!s.empty()){
            nums.push_back(s.top());
            s.pop();
        }
        return nums.size();
    }
};