1493. Longest Subarray of 1's After Deleting One Element -: 

Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's
in the resulting array. Return 0 if there is no such subarray.


// Example 1:
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
  
// Example 2:
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
  
// Example 3:
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
 

// Constraints:
// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

// find the length of the longest subarray which contains atmost "1" 0's.  

class Solution { 
public: // S.W. -: 
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(); 
        int i=0;
        int j=0;
        int zero=0;
        int len=0;
        int mxlen=0;
        while(j<n){
            if(nums[j]==0){
                zero++; 
            }
            while(zero>1){
                if(nums[i]==0){
                    zero--; 
                }
                i++; 
            }
            len=j-i+1;
            mxlen=max(mxlen, len); 
            j++; 
        }
        return mxlen-1;
    }
};



