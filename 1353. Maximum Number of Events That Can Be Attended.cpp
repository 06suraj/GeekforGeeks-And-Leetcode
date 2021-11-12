class Solution {
public:
    
     //HERE WE FIRST ITERATE OVER THE DAYS AND FOR A PARTICULAR DAY WE WILL GREEDILY PICK THAT ONGOING EVENT WHOSE ENDING TIME IS LEAST because for other events that are going on ,we might get a chance to visit them later( but not always, in case we do not get the chance to visit other events we will anyway lose one event). 
    
// For keeping track of ending times of ongoing events we use a priority queue.
    
// If there are no meetings going on a particular day, we don't attend any meeting.
    
    static bool  cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size(),ans=0;
       sort(events.begin(),events.end(),cmp);
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        for(int day=1;day<=100000;day++){
            
            // remove all the events which are already over
            while(!pq.empty() and pq.top()<day)pq.pop();
            
             //insert deadlines of all events that start today
            while(i<n and events[i][0]==day){
              pq.push(events[i][1]);
               i++;
             }
              
            //if there are any events we can attend today we 
            //attend the event with smallest endtime
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            
            //if all elements are processed then stop 
            if(pq.empty()&&i==n)
                break;
            
            
        }
        return ans;
        
    }
};
