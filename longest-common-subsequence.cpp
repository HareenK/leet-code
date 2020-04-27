1143. Longest Common Subsequence
Medium
1143: 

Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int col = text1.size();
        int row = text2.size();
        
        vector<vector<int>> dp (row+1, vector<int>(col+1, 0));
        
        for (int r = 1; r <= row; r++) {
            for (int c = 1; c <= col; c++) {
            
                // Crucial logic : If the current character is same understand the logic correctly. 
                
                dp[r][c] = (text1[c-1] == text2[r-1]) ? 1 + dp[r-1][c-1] : 
                                                        max(dp[r-1][c],dp[r][c-1]);          
            }
        }
        
        // for (auto row : dp) {
        //     for (auto col : row) {
        //         cout << col << " ";
        //     }
        //     cout << endl;
        // }
        
        return dp[row][col];
    }
};
