239. Sliding Window Maximum -: 

You are given an array of integers nums, there is a sliding window of size k which is
moving from the very left of the array to the very right. You can only see the k numbers in 
the window. Each time the sliding window moves right by one position.
Return the max sliding window.


// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
  
// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return {};
        
        // Arrays to store max elements for the left and right windows
        vector<int>leftMax(n), rightMax(n);
        
        // Fill leftMax array
        for(int i=0; i<n; i++){
            if(i%k==0){
                // Start of a new block
                leftMax[i]=nums[i];
            }else{
                // Compare with the previous element in the block
                leftMax[i]=max(leftMax[i-1],nums[i]);
            }
        }
        
        // Fill rightMax array
        for(int i=n-1; i>=0; i--){
            if(i==n-1 || (i+1)%k==0){
                // Start of a new block
                rightMax[i]=nums[i];
            }else{
                // Compare with the next element in the block
                rightMax[i]=max(rightMax[i+1],nums[i]);
            }
        }
        
        // Resultant array
        vector<int>ans(n-k+1);
        
        // Calculate the max for each window
        for(int i=0; i<n-k+1; i++){
            ans[i]=max(rightMax[i], leftMax[i+k-1]);
        }

        return ans;
    }
};


