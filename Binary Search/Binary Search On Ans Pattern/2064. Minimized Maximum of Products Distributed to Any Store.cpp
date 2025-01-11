// 2064. Minimized Maximum of Products Distributed to Any Store -: 


// You are given an integer n indicating there are n specialty retail stores. 
// There are m product types of varying amounts, which are given as a 0-indexed 
// integer array quantities, where quantities[i] represents the number of products 
// of the ith product type.
// You need to distribute all products to the retail stores following these rules:

// A store can only be given at most one product type but can be given any amount of it.
// After distribution, each store will have been given some number of products (possibly 0). 
// Let x represent the maximum number of products given to any store. You want x to be as small 
// as possible, i.e., you want to minimize the maximum number of products that are given to any store.
// Return the minimum possible x.

 

// Example 1:
// Input: n = 6, quantities = [11,6]
// Output: 3

// Explanation: One optimal way is:
// - The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
// - The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
// The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.

// Example 2:
// Input: n = 7, quantities = [15,10,10]
// Output: 5

// Explanation: One optimal way is:
// - The 15 products of type 0 are distributed to the first three stores in these amounts: 5, 5, 5
// - The 10 products of type 1 are distributed to the next two stores in these amounts: 5, 5
// - The 10 products of type 2 are distributed to the last two stores in these amounts: 5, 5
// The maximum number of products given to any store is max(5, 5, 5, 5, 5, 5, 5) = 5.

// Example 3:
// Input: n = 1, quantities = [100000]
// Output: 100000

// Explanation: The only optimal way is:
// - The 100000 products of type 0 are distributed to the only store.
// The maximum number of products given to any store is max(100000) = 100000.
 

// Constraints:

// m == quantities.length
// 1 <= m <= n <= 105
// 1 <= quantities[i] <= 105


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        int mini = 1;
        int maxi = *max_element(quantities.begin(), quantities.end());

        // Perform Binary Search -:
        while (mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;
            int sum = 0;

            // Calculate the total number of stores needed
            for (int i = 0; i < m; i++) {
                sum += quantities[i] / mid;
                if (quantities[i] % mid != 0) {
                    sum += 1; // Add an extra store for the remainder
                }
            }

            // Check if the number of stores needed is within the limit
            if (sum <= n) {
                maxi = mid - 1; // Try for a smaller maximum quantity
            } else {
                mini = mid + 1; // Increase the minimum bound
            }
        }

        return mini;
    }
};

int main() {
    Solution solution;

    // Input
    int n; // Number of stores
    cout << "Enter the number of stores (n): ";
    cin >> n;

    int m; // Number of product types
    cout << "Enter the number of product types (m): ";
    cin >> m;

    vector<int> quantities(m);
    cout << "Enter the quantities of each product type: ";
    for (int i = 0; i < m; i++) {
        cin >> quantities[i];
    }

    // Output
    int result = solution.minimizedMaximum(n, quantities);
    cout << "The minimized maximum quantity per store is: " << result << endl;

    return 0;
}
