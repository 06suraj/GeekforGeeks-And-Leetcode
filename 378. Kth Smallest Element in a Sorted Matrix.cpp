class Solution {
private:
    int cntSmaller(vector<vector<int>>& matrix,int k){
        int n=matrix.size(),m=matrix[0].size(),cnt=0,c=m-1;
        for(int i=0;i<n;i++){
            while(c>=0 and matrix[i][c]>k)c--;
            cnt+=c+1;
        }
        return cnt;
        
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        priority_queue<int>pq;   // build a max heap and traverse the whole matrix , and as soon as the size of heap is >k pop the max element(root)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k)pq.pop();
            }
        }
        
        /*T.C=O(n*m*log(k));
        S.C=O(k); */
        
       // return pq.top();
        
  /* ->   above approach is not utilising the fact that the matrix are sorted in rowwise and columnwise so there is a better approach than this which is to find k th smallest element in n sorted rows using min heap
          
   ->      We start the pointers to point to the beginning of each rows, then we iterate k times, for each time ith, the top of the minHeap is the ith smallest element in the matrix. We pop the top from the minHeap then add the next element which has the same row with that top to the minHeap(https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise)*/
      priority_queue<vector<int>,vector<vector<int>>,greater<>>minHeap;
        int ans,row,col;
      for(int i=0;i<min(n,k);i++)minHeap.push({matrix[i][0],i,0});
      for(int i=1;i<=k;i++){
          auto to=minHeap.top();
          minHeap.pop();
           ans=to[0],row=to[1],col=to[2];
          if(col+1<m)minHeap.push({matrix[row][col+1],row,col+1});
      }
        
        /*T.C=O(K*log(k));
        S.C=O(k); */
        
        //return ans;
        
        
  /*-> there is another approach which helps to optimise our space to O(1) using binary search (https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise)*/
        
      int lb=matrix[0][0],ub=matrix[n-1][m-1];
        ans=-1;
      while(lb<=ub){
          int mid=lb+(ub-lb)/2;
          if(cntSmaller(matrix,mid)<k){
              lb=mid+1;
          }else{
              ans=mid;
              ub=mid-1;
          }
      }
        
         /*T.C=O((N+M)*log(max-min));
        S.C=O(1); */
        
        return ans;
    }
};
