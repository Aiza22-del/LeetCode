/*
151. Reverse Words in a String
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Constraints:
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        int len = 0;

        while (s[len] != '\0')
        {
            len++;
        }

        char* begin = &s[0];
        char* end = &s[0] + len - 1;
        char ch;

        for (int i = 0; i < len / 2; i++)
        {
            ch = *end;
            *end = *begin;
            *begin = ch;
            begin++;
            end--;
        }

        int start = 0;

        for (int end = 0; end <= len; end++)
        {
            if (end == len || s[end] == ' ')
            {
                int left = start;
                int right = end - 1;
                while (left < right)
                {
                    char temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                    left++;
                    right--;
                }
                start = end + 1;
            }
        }

        string result;
        bool fw = true;
        int i = 0;
        while (i < len)
        {
            while (i < len && s[i] == ' ')
            {
                i++;
            }
            if (i < len && !fw)
            {
                result += ' ';
            }

            while (i < len && s[i] != ' ')
            {
                result += s[i];
                i++;
            }
            fw = false;
        }

        return result;
    }
};