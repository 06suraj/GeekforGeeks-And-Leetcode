class TopVotedCandidate {
public:
    map<int,int>ma;
    map<int,int>vote;
    int maxCnt,person;
    vector<int>time;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        ma.clear();
        vote.clear();
        time.clear();
        maxCnt=-1,person=-1;
        for(int i=0;i<times.size();i++){
            time.push_back(times[i]);
            vote[persons[i]]++;
            if(vote[persons[i]]>=maxCnt){
                maxCnt=vote[persons[i]];
                person=persons[i];
                ma[times[i]]=person;
                
            }else ma[times[i]]=person;
        }
    }
    
    int q(int t) {
        int lb=0,ub=time.size()-1,curr=-1;
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(time[mid]>t)ub=mid-1;
            else{
                curr=ma[time[mid]];
                lb=mid+1;
            }
        }
        return curr;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
