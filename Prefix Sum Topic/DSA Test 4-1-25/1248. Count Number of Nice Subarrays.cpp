1248. Count Number of Nice Subarrays -: 
Given an array of integers nums and an integer k. 
A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
  
Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
  
Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16



Code in C++ -: 

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        int ans=0;

        unordered_map<int, int>mp;
        int oddcount=0; 
        mp[oddcount]=1;

        for(int i=0; i<n; i++){
            if(nums[i]%2!=0){ // odd
                oddcount++;
            }
            int remaining=oddcount-k;
            if(mp.find(remaining)!=mp.end()){ // present
                ans+=mp[remaining]; 
            }
            mp[oddcount]++; // store odd no.s and their freq. 
        }
        return ans; 
    }
};

