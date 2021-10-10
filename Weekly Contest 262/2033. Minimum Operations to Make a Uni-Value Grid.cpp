class Solution {
public:
   // taken from https://www.geeksforgeeks.org/minimum-operations-of-given-type-to-make-all-elements-of-a-matrix-equal/
    int minOperations(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> arr(n * m, 0);
 
    int mod = matrix[0][0] % k;
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i * m + j] = matrix[i][j];
 
            // If not possible
            if (matrix[i][j] % k != mod) {
                return -1;
            }
        }
    }
 
    // Sort the array to get median
    sort(arr.begin(), arr.end());
 
    int median = arr[(n * m) / 2];
 
    // To count the minimum operations
    int minOperations = 0;
    for (int i = 0; i < n * m; ++i)
        minOperations += abs(arr[i] - median) / k;
 
    // If there are even elements, then there
    // are two medians. We consider the best
    // of two as answer.
    if ((n * m) % 2 == 0)
    {
       int median2 = arr[( (n * m) / 2) - 1];
       int minOperations2 = 0;
       for (int i = 0; i < n * m; ++i)
          minOperations2 += abs(arr[i] - median2) / k;
 
       minOperations = min(minOperations, minOperations2);
    }
 
    // Return minimum operations required
    return minOperations;
    }
};
