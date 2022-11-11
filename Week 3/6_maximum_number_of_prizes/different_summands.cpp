#include <bits/stdc++.h>
using namespace std;

/// @brief distribute a number in a sequence inc series
/// @param n
/// @return list of the series
vector<int> optimal_summands(int n)
{

  vector<int> summands;
  int candies = n;
  if (n == 1)
  {
    return {1};
  }
  for (size_t i = 1; i <= candies; i++)
  {
    if (i <= n)
    {
      n -= i;
      summands.push_back(i);
    }
    else
    {
      summands[i - 2] += n;
      break;
    }
  }

  return summands;
}

/// @brief stress testing function

// void test_function()
// {
//   for (size_t i = 0; i < 100; i++)
//   {
//     vector<int> summands = optimal_summands(i);
//     std::cout << i << " => ";
//     for (size_t i = 0; i < summands.size(); ++i)
//     {
//       std::cout << summands[i] << ' ';
//     }
//     cout << endl;
//   }
//   cout << "Finished" << endl;
// }

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
  // test_function();
}

// 1 2 3 4 5 6 7

// 1 , n=7
// 2 , n=5
// 3, n=2
// 4,