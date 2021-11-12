class Solution {
public:
    int memo[100000];
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    
    // just like o/1 knap sack  we will check whethether we can take the current job or not , and caluclate the maximum from both the scenario , and since we are iterating  each element once and searcg for next feasible job , its t.c is o(n^2); 
    int solve_memo(vector<vector<int>>&job,int index){
        if(index==job.size())return 0;
        
        if(memo[index]!=-1) return memo[index];
        
        int next_index=-1,include=0,exclude=0;
        
        // linearly search for next index whose ending time is >= our current index starting time so that there is no overlap , so it will take o(n) time this can be optimised to o(logn) using binary search discussed in next function
        for(int i=index+1;i<job.size();i++){
            if(job[i][0]>=job[index][1]){
                next_index=i;
                break;
            }
        }
        if(next_index==-1)include+=job[index][2];
        else include=job[index][2]+solve_memo(job,next_index);
    
        
        exclude=solve_memo(job,index+1);
        return memo[index]=max(include,exclude);
    }
    
    int solve_memo_optimised(vector<vector<int>>&job,int index){
        if(index==job.size())return 0;
        
        if(memo[index]!=-1) return memo[index];
        
        int next_index=-1,include=0,exclude=0,l=index+1,r=job.size()-1;
        
        // here we have just optimised the linear search to binary search so that t.c. is o(nlogn) 
        while(l<=r){
            int mid=l+(r-l)/2;
            if(job[mid][0]>=job[index][1])
            {   next_index=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        
        if(next_index==-1)include+=job[index][2];
        else include=job[index][2]+solve_memo_optimised(job,next_index);
    
        
        exclude=solve_memo_optimised(job,index+1);
        return memo[index]=max(include,exclude);
    }
    
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(memo,-1,sizeof(memo));
        vector<vector<int>>jobs;
        int n=startTime.size();
        for(int i=0;i<n;i++){
            vector<int>temp;
            temp.push_back(startTime[i]);
            temp.push_back(endTime[i]);
            temp.push_back(profit[i]);
            jobs.push_back(temp);
        }
        sort(jobs.begin(),jobs.end(),comp);
        return solve_memo_optimised(jobs,0);
        
    }
};
