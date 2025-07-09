// String: Valid Palindrome
// Leetcode Problem: 125
// Problem Link: https://leetcode.com/problems/valid-palindrome/
// Problem Statement: Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.


class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;

        //When string is empty
        if(s.size() == 0) return true;
        while(i<=j){
            //condiiton to check if it is alphanumeric
            if(isalnum(s[i]) && isalnum(s[j]))
            {
                //if both are alphanumeric then check if they are equal
                if(tolower(s[i]) == tolower(s[j]))
                    {
                        i++;
                        j--;
                    }
                    // if they are not equal then return false
                else if(tolower(s[i]) != tolower(s[j])) return false;
                    

            }
            // s[i] is not alpha numeric then skip it
            else if(!isalnum(s[i]))
                {
                    i++;
                }
            // s[j] is not alpha numeric then skip it
            else if(!isalnum(s[j]))
                {
                    j--;
                }

        }
        return true;
    }
};