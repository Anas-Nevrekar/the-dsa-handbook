// String: Reverse a word in a string
// Leetcode Problem: 151
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/description/
// Problem Statement: Given an input string s, reverse the order of the words.

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end()); //reverse the entire string first
        string ans="";
        for(int i =0; i<n;i++){
            string word ="";
            while(i<n && s[i]!=' '){ // collect each character of the word until a space is encountered
                word += s[i]; // add the character to the word
                i++;
            }
            reverse(word.begin(), word.end()); // reverse the word to get it in correct order
            if(word.length()>0){
                ans +=" "+word; // add the word to the answer string with a space before it
            }
        }
        return ans.substr(1); // return the answer string without the leading space
    }
};

// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) since we are using constant space for the answer string