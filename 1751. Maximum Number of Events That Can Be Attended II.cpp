class Solution {
public:
    map<pair<int,int>,int>memo;
    
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    
      int solve_memo_optimised(vector<vector<int>>&job,int index,int k){
        if(index==job.size() or k<=0)return 0;
        
        if(memo.find({index,k})!=memo.end()) return memo[{index,k}];
        
     int next_index=-1,include=0,exclude=0,l=index+1,r=job.size()-1;
        
        // here we have just optimised the linear search to binary search so that t.c. is o(nlogn) 
        while(l<=r){
            int mid=l+(r-l)/2;
            if(job[mid][0]>job[index][1])
            {   next_index=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        
        if(next_index==-1)include+=job[index][2];
        else include=job[index][2]+solve_memo_optimised(job,next_index,k-1);
    
        
        exclude=solve_memo_optimised(job,index+1,k);
        return memo[{index,k}]=max(include,exclude);
    }
    
    
    int maxValue(vector<vector<int>>& events, int k) {
        memo.clear();
        sort(events.begin(),events.end(),comp);
        return solve_memo_optimised(events,0,k);
    }
};
