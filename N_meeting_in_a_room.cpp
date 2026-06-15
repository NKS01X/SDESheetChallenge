class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        vector<pair<int,int>> meet;
        int n = start.size();
        for(int i = 0;i < n; ++i) {
            meet.push_back({start[i],end[i]});
        }
        sort(meet.begin(),meet.end(),[](const pair<int,int> &a,const pair<int,int> &b) {
            int stT1 = a.first,  stT2 = b.first;
            int enT1 = a.second, enT2 = b.second;

            return enT1 < enT2;
        });

        int last = -1;
        int tot_meet = 0;
        for(auto &[startT,endT]: meet) {
            if(last < startT) {
                ++tot_meet;
                last = endT;
            }
        }
        return tot_meet;
    }
};
