class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      int n=arr.size();
        int leftMax[n],rightMax[n];  // to store the left and right maximum element index which is greater than current element index
        memset(leftMax,-1,sizeof(leftMax));
        stack<int>st;  // this stack will give me the farthest index which is greater than current index element 
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
                leftMax[i]=i;
            }else{
                if(arr[st.top()]<arr[i]){leftMax[i]=i;st.push(i);}
                else{
                    while(!st.empty() and arr[st.top()]>=arr[i])st.pop();
                    if(st.empty())leftMax[i]=0;
                    else leftMax[i]=st.top()+1;
                    st.push(i);
                }
            }
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                rightMax[i]=i;
            }else{
                if(arr[st.top()]<arr[i]){rightMax[i]=i;st.push(i);}
                else{
                    while(!st.empty() and arr[st.top()]>arr[i])st.pop();
                    if(st.empty())rightMax[i]=n-1;
                    else rightMax[i]=st.top()-1;
                    st.push(i);
                }
            }
        }
       long long int s=0;
        for(int i=0;i<n;i++){
            // cout<<leftMax[i]<<" "<<rightMax[i]<<endl;
           long long int x1=((rightMax[i]-i+1)*(i-leftMax[i]))%1000000007;
            long long int x2=rightMax[i]-i;
            s=s%1000000007+(x1*(arr[i]%1000000007))%1000000007+(x2*(arr[i]%1000000007))%1000000007+arr[i]%1000000007;
            
            
        }
        
        return s;
        
     
    }
};
