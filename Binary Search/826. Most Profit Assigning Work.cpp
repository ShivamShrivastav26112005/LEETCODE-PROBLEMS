826. Most Profit Assigning Work -: 

You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.
For example, if three workers attempt the same job that pays $1, then the total profit will be $3. 
If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.

 

Example 1:
Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
  
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] 
and they get a profit of [20,20,30,30] separately.
  
Example 2: 
Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
Output: 0

  
Constraints:
  
n == difficulty.length
n == profit.length
m == worker.length
1 <= n, m <= 104
1 <= difficulty[i], profit[i], worker[i] <= 105   



class Solution { // Using Prefix Algo -: 
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        
        int maxi=*max_element(difficulty.begin(), difficulty.end());

        vector<int>preMax(maxi+1, 0);

        for(int i=0; i<n; i++){
            preMax[difficulty[i]]=max(preMax[difficulty[i]], profit[i]); 
        }

        for(int i=1; i<=maxi; i++){
            preMax[i]=max(preMax[i], preMax[i-1]);
        }

        int sum=0;
        for(int i=0; i<worker.size(); i++){
            if(worker[i]>maxi){
                sum+=preMax[maxi];  
            }else{
                sum+=preMax[worker[i]]; 
            }
        }
        return sum; 
    }
};



Complexity -: 
  
Time Complexity -: 
Filling prefixMax: O(n)
Building cumulative max: O(maximum)
Calculating total profit: O(m)
  
Total -: O(n+maximum+m), where n is the size of difficulty, maximum is the maximum difficulty, 
and m is the size of worker.

Space Complexity -: 
O(maximum) for the prefixMax array.

