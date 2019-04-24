/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (39.05%)
 * Total Accepted:    32.6K
 * Total Submissions: 83.5K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str, str1;
        for (auto i : s)
        {
            if (isalpha(i))  //isalpha(i)函数表示只有i为字母时为真
                str += tolower(i);
            if (isdigit(i))  //isdigit(i)函数表示中有i为数字时为真
                str += i;
        }
        str1 = str;
        reverse(str.begin(), str.end());
        return str1 == str;
    }
};
