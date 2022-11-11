#include <bits/stdc++.h>
using namespace std;

/// @brief get money change iteratively
/// @param money
/// @return number of coins

int get_change_iter(int money)
{
  int n = 0;
  while (money > 0)
  {
    if (money >= 10)
    {
      money -= 10;
    }
    else if (money >= 5)
    {
      money -= 5;
    }
    else
    {
      money -= 1;
    }
    n++;
  }
  return n;
}

/// @brief get money change by mathmatical equation
/// @param money
/// @return number of coins

int get_change_math(int money)
{
  return (money / 10) + ((money % 10) / 5) + (money % 5);
}

/// @brief get money change recursively
/// @param money
/// @return number of coins

int get_change_rec(int money)
{
  if (money == 0)
  {
    return 0;
  }
  else
  {
    int maxCoin = 1;
    if (money >= 10)
    {
      maxCoin = 10;
    }
    else if (money >= 5)
    {
      maxCoin = 5;
    }
    return (1 + get_change_rec(money - maxCoin));
  }
}

/// @brief stress testing function

// void test_function()
// {
//   for (size_t i = 1; i < 1000; i++)
//   {
//     bool isTrue = get_change_rec(i) == get_change_math(i);
//     if (isTrue)
//     {
//       cout << get_change_math(i) << endl;
//     }
//     else
//     {
//       cout << "Wrong at (" << i << ")=> " << get_change_rec(i) << " - " << get_change_math(i) << endl;
//       break;
//     }
//   }
//   cout << "Finished" << endl;
// }

int main()
{
  int money;
  cin >> money;
  cout << get_change_iter(money) << '\n';

  // test_function();
}
