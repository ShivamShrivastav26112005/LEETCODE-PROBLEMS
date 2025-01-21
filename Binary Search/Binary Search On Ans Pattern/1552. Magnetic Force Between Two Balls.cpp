1552. Magnetic Force Between Two Balls -: 
  
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls 
if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], 
Morty has m balls and needs to distribute the balls into the baskets such that the minimum 
magnetic force between any two balls is maximum.
Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
Given the integer array position and the integer m. Return the required force.

 

// Example 1:
// Input: position = [1,2,3,4,7], m = 3
// Output: 3
  
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force 
// between ball pairs [3, 3, 6]. The minimum magnetic force is 3.
// We cannot achieve a larger minimum magnetic force than 3.
  
// Example 2:
// Input: position = [5,4,3,2,1,1000000000], m = 2
// Output: 999999999
  
// Explanation: We can use baskets 1 and 1000000000.
 

// Constraints:

// n == position.length
// 2 <= n <= 105
// 1 <= position[i] <= 109
// All integers in position are distinct.
// 2 <= m <= position.length



class Solution { // Pattern -: Binary Search On Ans -: 
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(), position.end()); 

        // Perform B.S. Using 2 Pointers -: 
        int mini=1;
        int maxi=position[n-1]-position[0]; 

        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            int placed=position[0]; // first ball is placed at 0th idx 
            int count=1; // then count=1 becoz 1 ball is used -: 
            // checking and finding position for another balls -: 
            for(int i=1; i<n; i++){
                if(position[i]-placed>=mid){
                    count++; // yes we can placed 
                    placed=position[i]; // we found new position and 
                    // again checking starts from these new position 
                }
            }
            // Condiiton for BS -: 
            if(count>=m){ // valid 
                mini=mid+1; // update mini 
            }else{ // not valid 
                maxi=mid-1; 
            }
        }
        return maxi; 
    }
};

