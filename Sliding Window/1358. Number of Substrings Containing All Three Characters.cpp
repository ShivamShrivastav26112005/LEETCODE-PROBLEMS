1358. Number of Substrings Containing All Three Characters. 

Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.


// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c 
// are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
  
// Example 2:
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of 
// the characters a, b and c are "aaacb", "aacb" and "acb". 
  
// Example 3:
// Input: s = "abc"
// Output: 1
 

// Constraints:
// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.



class Solution { // Sliding Window -: 
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int count=0; 
        // S.W. -: 
        int i=0;
        int j=0;
        unordered_map<char, int>mp;
        while(j<n){
            mp[s[j]]++;

            // found a valid window which contains atleast 1 a,b & c then no need to traverse 
            // further becoz after this vald window all the substrings are valid use formula
            // and all the substrings -: 
            while(mp['a']>0 && mp['b']>0 &&mp['c']>0){ 
                count+=n-j; 
                // remove leftmost char. / shrink 
                mp[s[i]]--;
                i++; // move forward and make a new window -: 
            }
            j++;
        }
        return count; 
    }
};


