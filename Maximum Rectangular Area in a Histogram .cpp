class Solution
{
    public:
   
    
 /*   1->  TO FIND THE MAXIMUM RECTANGULAR AREA, FIRST WE NEED TO FIND FOR EVERY BAR IF CONSIDERED AS A FULL WWHAT WILL BE THE AREA IT WILL HAVE , AND AMONG ALL SUCH AREAS , THE MAXIMUM WILL BE ANSWWER 
     2->   TO FIND AREA OF EACH BAR (CONSISTING ITSELF AS A FULL ) WE HAVE TO FIND KEEP TRACK OF LEFTMOST NEXT SMALLER HEIGHT BAR AND RIGHTMOST SMALLER BAR , SO THAT (RIGHTMOST-LEFTMOST-1)*CURR_HEIGHT WILL ABE AREA OF THAT BAR IF CONSIDERED AS A FULL*/
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
     vector<long long >left,right;//  keep track of leftmost and rightmost immediate smaller bar for each bar 
      stack<long long>s; //  help to maintain order in increasing order
    for(int i=0;i<n;i++)
    {
        if(s.empty()){
            left.push_back(0);
            s.push(i+1);
        }
        else
        {
            if(arr[s.top()-1]<arr[i])
            {
                left.push_back(s.top());
                s.push(i+1);
            }else
            {
                while(!(s.empty()) and arr[s.top()-1]>=arr[i])
                s.pop();
                if(s.empty())
                left.push_back(0);
                else left.push_back(s.top());
                s.push(i+1);
            }
        }
    }    
    while(!(s.empty()))s.pop();
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty()){
            right.push_back(n+1);
            s.push(i+1);
        }
        else
        {
            if(arr[s.top()-1]<arr[i])
            {
                right.push_back(s.top());
                s.push(i+1);
            }else
            {
                while(!(s.empty()) and arr[s.top()-1]>=arr[i])
                s.pop();
                if(s.empty())
                right.push_back(n+1);
                else right.push_back(s.top());
                s.push(i+1);
                
            }
        }
    }
    reverse(right.begin(),right.end());
    long long ans=LLONG_MIN;
    for(int i=0;i<n;i++)
    ans=max(ans,(right[i]-left[i]-1)*arr[i]);
    return ans;
    
    
    }
    
};
