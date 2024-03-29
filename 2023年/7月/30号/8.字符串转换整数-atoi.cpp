/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <iostream>
#include <string>
using namespace std;
/**
Accepted
1086/1086 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 63.31 % of cpp submissions (6.9 MB)
 */
// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        int index = 0, n = str.size(), sign = 1, res = 0;
        // 处理前置空格
        while (index < n && str[index] == ' ')
        {
            ++index;
        }
        // 处理符号
        if (index < n && (str[index] == '+' || str[index] == '-'))
        {
            sign = str[index++] == '+' ? 1 : -1;
        }
        // 处理数字
        while (index < n && isdigit(str[index]))
        {
            int digit = str[index] - '0';
            // 判断是否溢出
            if (res > (INT_MAX - digit) / 10)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            ++index;
        }
        return res * sign;
    }
};
// @lc code=end
