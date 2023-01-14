#include <bits/stdc++.h>
using namespace std;

int DpChange(int m, vector<int> coins)
{

  vector<int> minNumCoins(m + 1);

  minNumCoins[0] = 0;

  for (int i = 1; i <= m; i++)
  {
    minNumCoins[i] = INT_MAX;
    for (int j = 0; j < coins.size(); j++)
    {

      if (i >= coins[j])
      {
        int numCoins = minNumCoins[i - coins[j]] + 1;
        if (numCoins < minNumCoins[i])
        {
          minNumCoins[i] = numCoins;
        }
      }
    }
  }
  return minNumCoins[m];
}

int main()
{

  int m;
  std::cin >> m;
  std::cout << DpChange(m, {1, 3, 4}) << '\n';
}
