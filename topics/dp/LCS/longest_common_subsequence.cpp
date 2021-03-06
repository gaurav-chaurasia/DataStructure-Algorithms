#include <bits/stdc++.h>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]\n";

class Solution
{

public:
    // LCS
    // returns the length of LCS
    int longest_common_subsequence(int n, string str1, int m, string str2)
    {
        if (n == 0 or m == 0)
            return 0;
        
        if (str1[n - 1] == str2[m - 1]) 
        {
            return 1 + longest_common_subsequence(n - 1, str1, m - 1, str2);
        }
        else 
        {
            return max(
                longest_common_subsequence(n, str1, m - 1, str2),
                longest_common_subsequence(n - 1, str1, m, str2)
            );
        }
    }

    // LCS
    // returns the length of LCS
    int longest_common_subsequence_memoized(int n, string str1, int m, string str2, vector<vector<int>> dp)
    {
        if (n == 0 or m == 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];

        if (str1[n - 1] == str2[m - 1])
        {
            return dp[n][m] = 1 + longest_common_subsequence_memoized(n - 1, str1, m - 1, str2, dp);
        }
        else
        {
            return dp[n][m] = max(
                longest_common_subsequence_memoized(n, str1, m - 1, str2, dp),
                longest_common_subsequence_memoized(n - 1, str1, m, str2, dp)
            );
        }
    }

    // LCS
    // returns the length of LCS
    int longest_common_subsequence_td(int n, string str1, int m, string str2)
    {
        int dp[n + 1][m + 1];

        for (int i = 0, j = 0; j <= m; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else 
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    string S1 = "abcdgh";
    string S2 = "abedfhr";
    int n = S1.size();
    int m = S2.size();
    // recursive method 
    DEB(SOL->longest_common_subsequence(n, S1, m, S2));

    // memoized method / bottom-up method  
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    DEB(SOL->longest_common_subsequence_memoized(n, S1, m, S2, dp));

    // top-down method
    DEB(SOL->longest_common_subsequence_td(n, S1, m, S2));

    delete SOL;
    return 0;
}
