#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        // Initialize the search range
        int mini = 1;
        int maxi = *max_element(nums.begin(), nums.end()); // Get the maximum element in nums

        // Perform binary search
        while (mini < maxi) {
            int mid = mini + (maxi - mini) / 2;
            int sum = 0;

            // Calculate the sum of rounded-up divisions
            for (int i = 0; i < n; i++) {
                sum += (nums[i] + mid - 1) / mid; // Equivalent to ceil(nums[i] / mid)
            }

            // Adjust the search range based on the threshold
            if (sum > threshold) {
                mini = mid + 1; // Too small divisor, increase it
            } else {
                maxi = mid; // Valid divisor, try smaller
            }
        }

        return mini; // The smallest valid divisor
    }
};

int main() {
    int n, threshold;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input the threshold
    cout << "Enter the threshold: ";
    cin >> threshold;

    // Create an object of Solution class
    Solution solution;

    // Find and print the smallest divisor
    int result = solution.smallestDivisor(nums, threshold);
    cout << "The smallest divisor is: " << result << endl;

    return 0;
}
