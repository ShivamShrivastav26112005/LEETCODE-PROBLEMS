1248. Count Number of Nice Subarrays -: 

Given an array of integers nums and an integer k.
A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.

 
// Example 1:
// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
  
// Example 2:
// Input: nums = [2,4,6], k = 1
// Output: 0
// Explanation: There are no odd numbers in the array.
  
// Example 3:
// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// Output: 16
 

// Constraints:

// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10^5
// 1 <= k <= nums.length


  
// Sliding Window By Using 2 Pointers (start and end)-: 

class Solution { 
public:

    int solve1(vector<int>& nums, int n, int k, int countsubarray){
        int start=0;
        int end=0;
        while(end<n){
            if(nums[end]%2!=0){ // odd 
                k--; 
            }
            while(k<0){
                if(nums[start]%2!=0){ // odd 
                    k++;
                }
                start++;
            }
            // count no.of subarrays everytime 
            countsubarray+=(end-start+1);
            end++; 
        }
        return countsubarray ;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        int countsubarray1=solve1(nums, n, k, 0);
        int countsubarray2=solve1(nums, n, k-1, 0);

        return countsubarray1-countsubarray2; 
    }
};



// Time Complexity: O(n), where n is the size of the array nums.
// Space Complexity: O(1).



