class Solution {
public:
    vector<int>find(vector<int>arr,int x){
        int lb=0,ub=arr.size()-1;
        vector<int>pos(2);
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(arr[mid]<=x){
                pos[0]=mid;
                lb=mid+1;
            }else ub=mid-1;
        }
        lb=0,ub=arr.size()-1;
        while(lb<=ub){
            int mid=lb+(ub-lb)/2;
            if(arr[mid]<x){
                lb=mid+1;
            }else{
                pos[1]=mid;
                ub=mid-1;
            }
        }
        return pos;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int>pos=find(arr,x);
        vector<int>ans1,ans2;
        int i=pos[0],j=pos[1],size=0;
        if(pos[0]==pos[1]){
            ans1.push_back(arr[pos[0]]);
            i--,j++,size++;
       }
       else if(arr[pos[0]]==arr[pos[1]]){
           int temp=min(pos[0],pos[1]);
           i=temp,j=temp+1;
       }
      while(size<k and i>=0 and j<n){
          if(abs(arr[i]-x)>abs(arr[j]-x))j++;
          else if(abs(arr[i]-x)<=abs(arr[j]-x))i--;
          size++;
      }
      while(size<k and i>=0){i--,size++;}
      while(size<k and j<n){j++,size++;}
     vector<int>ans;
        if(j>=i)
        for(int i1=i+1;i1<j;i1++)ans.push_back(arr[i1]);
        else
         for(int i1=i+1;i1<n;i1++)ans.push_back(arr[i1]);   
        return ans;
        
        // T.C=O(logn+k) , S.C=O(k) using binary search and two pointer
    }
};
