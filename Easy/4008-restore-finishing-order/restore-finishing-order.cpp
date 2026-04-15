class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>pos(friends.size(),-1);
        int index=0;
        for(auto j:order){
            for(auto i:friends){
                if(j==i){
                    pos[index]=j;
                    index++;
                }
            }
        }
        return pos;
    }
};