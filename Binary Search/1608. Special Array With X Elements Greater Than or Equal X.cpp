1608. Special Array With X Elements Greater Than or Equal X -: 

You are given an array nums of non-negative integers. nums is considered special if there exists a number x 
such that there are exactly x numbers in nums that are greater than or equal to x.
Notice that x does not have to be an element in nums.
Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

 

Example 1:
Input: nums = [3,5]
Output: 2
  
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
  
Example 2:
Input: nums = [0,0]
Output: -1
  
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
  
Example 3:
Input: nums = [0,4,3,0,4]
Output: 3
  
Explanation: There are 3 values that are greater than or equal to 3.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000



// Method-1-: 

class Solution {
public:
    int specialArray(vector<int>& nums){
        int n = nums.size(), val = 0;
        vector<int> count(n + 1, val);
        for(int i = 0; i < nums.size(); i++){
            int index = min(nums[i], n);
            count[index]++;
        }

        int total_right = 0;
        for(int i = nums.size(); i >= 0; i--){
            total_right += count[i];
            if(i == total_right)
                return i;
        }
        return -1;
    }
};



// Method-2-: 

class Solution { // Binary Search -: 
public:
    int getFirstGreaterOrEqual(vector<int>& nums, int val) {
        int start=0;
        int end=nums.size()-1;

        int index=nums.size();
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>=val) {
                index=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return index;
    }

    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1; i<=n; i++){
            int k=getFirstGreaterOrEqual(nums, i);
            if(n-k==i){
                return i;
            }
        }
        return -1;
    }
};

