// Leetcode-3-: Longest Substring Without Repeating Characters.

// Given a string s, find the length of the longest 
// substring without repeating characters.


// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.



// M-1-: // Using Set DS -: 

class Solution { 
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char>set;
        int i=0;
        int maxi=0;
        for(int j=0; j<n; j++){
            // not valid -: 
            while(set.find(s[j])!=set.end()){ // present 
                set.erase(s[i]); // delete the repeated char. 
                i++;
            }
            // valid -:
            set.insert(s[j]); // insert the char and if valid then find the maxlen
            maxi=max(maxi, j-i+1);
        }
        return maxi;
    }

    // if condition is valid at that time find the required ans 
    // like minlen, maxlen, print or store the ans. 
};  






// M-2-: // By Using Array -: Optimized

class Solution { 
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(); 
        vector<int> arr(256, 0);

        int mxLen=0; 

        int i=0;
        int j=0;
        while(j<n){
            // Increment the count of the curr char
            arr[s[j]]++; // expand 

            // If the char is repeated, reduce the window size from the left
            while(arr[s[j]]>1){ 
                arr[s[i]]--; // Decrement the count of the curr char
                i++; // shrink 
            }
            // mxlen update after every iteration -: 
            mxLen=max(mxLen, j-i+1);
            j++;
        }
        return mxLen;
    }
};



// Remember, To solve the Ques of strings always use array DS.TC=O(1), instead of set or map DS, TC=O(logn)