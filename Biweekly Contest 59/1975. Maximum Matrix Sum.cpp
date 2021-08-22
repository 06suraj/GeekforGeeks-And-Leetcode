class Solution {
public:
    //taken from https://www.geeksforgeeks.org/maximize-matrix-sum-by-repeatedly-multiplying-pairs-of-adjacent-elements-with-1/
    long long maxMatrixSum(vector<vector<int>>& A) {
        int N=A.size(),M=N;
       long long int sum = 0;
       int negative = 0;
 
    // Store minimum absolute
    // value present in the matrix
    int minVal = INT_MAX;
 
    // Traverse the matrix row-wise
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
 
            // Update sum
            sum += abs(A[i][j]);
 
            // If current element is negative,
            // increment the negative count
            if (A[i][j] < 0) {
                negative++;
            }
 
            // If current value is less than
            // the overall minimum in A[],
            // update the overall minimum
            minVal = min(minVal, abs(A[i][j]));
        }
    }
 
    // If there are odd number of negative
    // values, then the answer will be
    // sum of the absolute values of
    // all elements - 2* minVal
    if (negative % 2) {
        sum -= 2 * minVal;
    }
 
    // Print maximum sum
    return sum;
        
    }
};
