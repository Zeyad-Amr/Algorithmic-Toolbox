#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2)
{
  // write your code here
  int m = str1.size();
  int n = str2.size();
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    dp[i][0] = i;
  for (int j = 0; j <= n; j++)
    dp[0][j] = j;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
      int insertion = dp[i][j - 1] + 1;
      int deletion = dp[i - 1][j] + 1;
      int match = dp[i - 1][j - 1];
      int mismatch = dp[i - 1][j - 1] + 1;
      if (str1[i - 1] == str2[j - 1])
        dp[i][j] = std::min(insertion, std::min(deletion, match));
      else
        dp[i][j] = std::min(insertion, std::min(deletion, mismatch));
    }
  return dp[m][n];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
