/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator) //n是分子，d是分母
    {
        int s1 = numerator >= 0 ? 1 : -1;
        int s2 = denominator >= 0 ? 1 : -1;
        unordered_map<long long, int> m;
        long long num = abs((long long)numerator);
        long long den=abs((long long)denominator);
        long long out = num / den;
        long long rem = num % den;
        string res = to_string(out);
        if (s1 * s2 == -1 && (out > 0 || rem > 0))
            res = "-" + res;
        if (rem == 0)
            return res;
        res += ".";
        string s = "";
        int pos = 0;
        while (rem)
        {
            if (m.find(rem) != m.end())
            {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            pos++;
        }
        return res + s;
    }
};
