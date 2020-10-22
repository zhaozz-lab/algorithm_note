#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
int F(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return F(n - 1) + F(n - 2);
}


int dp[100] = {-1};
int Fdynamic(int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    else
    {
        dp[n] = Fdynamic(n - 1) + Fdynamic(n - 2);
        return dp[n];
    }
}


// 最大连续子序列和
void maximumContinuousSubsequenceSum()
{
    int subsequence[6] = { -2,11,-4,13,-5,-2 };
    int dp[6] = { 0,0,0,0,0,0 };
    dp[0] = subsequence[0];
    for(int i=1; i<6; i++)
    { 
        dp[i] = max((dp[i - 1] + subsequence[i]), subsequence[i]);
        cout << "the" << dp[i];
    }
}


void longestIncreasingSeuence()
{
    int subsequence[10] = {1, 2, 3, -5, -4, 1, 2, 13, -5, -2 };
    int dp[10] = { 0,0,0,0,0,0,0,0,0,0 };
    dp[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        if (subsequence[i] >= subsequence[i - 1])
            dp[i] = dp[i-1] + 1;
        else
        {
            dp[i] = 1;
        }
        //dp[i] = max((dp[i - 1] + subsequence[i]), subsequence[i]);
        cout<<"longgest increasing sequence "<< dp[i]<<endl;
    }
}


void LongestCommonSubsequence()
{
    const int N = 100;
    //char A[N], B[N];
    int dp[N][N];
    char A[N] = { 'a','b','c','d','a','b','e','f','g' };
    char B[N] = { 'a','b','e','f','g','c','h','t','s' };

    int lenA = strlen(A + 1);
    int lenB = strlen(B + 1);
    
    for (int i = 0; i < lenA; i++)
        dp[i][0] = 0;

    for (int j = 0; j < lenB; j++)
        dp[0][j] = 0;
    
    for(int i = 1;i<lenA+1;i++)
        for (int j = 1; j < lenB+1; j++)
        {
            if (A[i]==B[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    cout << "the lenA and lenB is " << lenA << "lenB: " << lenB << endl;
    cout << "the longest subsequence is " << dp[8][8] << endl;

}


//最长回文子串
void longestPalindromicString()
{
    char S[10] = { 'a','b','c','b','c','b','a','f','g' };
    int dp[10][10];
    int len = strlen(S), ans = 1;
    memset(dp, 0, sizeof(dp));
    //边界
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (i < len - 1) {
            if (S[i]==S[i+1])
            {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    //状态转移方程
    for (int L = 3; L < len; L++) {//枚举子串的长度
        for (int i = 0; i + L - 1 < len; i++) {
            int j = i + L - 1;
            if (S[i] == S[j] && dp[i+1][j-1]==1)
            {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    cout << "the ans is " << ans << endl;

}

int main()
{
    cout << F(5) << endl;

    for (int i = 0; i < 100; i++)
        dp[i] = -1;
    cout << Fdynamic(5) << endl;
    //最大连续子序列和
    maximumContinuousSubsequenceSum();

    //最长不下降子序列
    longestIncreasingSeuence();

    //最长公共子序列
    LongestCommonSubsequence();

    //最长回文子串

    longestPalindromicString();

    return 1;
}
