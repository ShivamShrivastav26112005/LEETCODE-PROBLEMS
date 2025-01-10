1760. Minimum Limit of Balls in a Bag -: 

Example 1:
Input: nums = [9], maxOperations = 2
Output: 3
  
Explanation: 
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.
  
Example 2:
Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
  
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.
 

Constraints:

1 <= nums.length <= 105
1 <= maxOperations, nums[i] <= 109


  
Algorithm:
The goal is to minimize the maximum size of a bag after performing at most maxOperations operations. Binary search on the maximum ball size is used to find the optimal solution.

Steps:
Define Search Space:

The smallest possible size of any bag is 1, and the largest is the maximum value in the array (max(nums)).
Binary Search:

Perform binary search on the maximum allowed size of a bag (mid).
For each mid, check if it is possible to split the bags such that the size of every bag is ≤ mid within maxOperations.
Check Feasibility (isPossible):

For each bag of size nums[i], calculate the number of operations required to split it into bags of size ≤ mid.
If the total operations exceed maxOperations, return false.
Adjust Search Space:

If it is possible to achieve a bag size of mid, move the search to smaller sizes (maxi = mid - 1).
Otherwise, move to larger sizes (mini = mid + 1).
Return the Result:

The mini pointer will hold the smallest valid maximum size after the binary search.


  
Code in C++ -: 

class Solution { // Binary Search On Ans. 
public:

    bool isPossible(vector<int>& nums, int ops, int mid) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            int rem = nums[i] / mid;
            if(nums[i] % mid == 0){
                ops -= rem - 1; // If divisible, reduce ops by (rem - 1).
            }else{
                ops -= rem; // If not divisible, reduce ops by rem.
            }
            if(ops < 0) return false; // ops -ve 
        }
        return true; 
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();

        // BS -: Using 2 pointer -: 
        int mini=1;
        // int maxi=*max_element(nums.begin(), nums.end()); 
        // OR -: 
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]>maxi){
                maxi=nums[i]; 
            }
        }

        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            if(isPossible(nums, maxOperations, mid)){
                maxi=mid-1;
            }else{
                mini=mid+1; 
            }
        }
        return mini; 
    }
};


Complexity -: 
  
Time Complexity -: 
-: Binary search runs in O(log(max(nums))).
-: Each feasibility check iterates over all elements, O(n). 

Total -: O(n⋅log(max(nums)))
  
Space Complexity -: O(1) (no extra space used).


