#include <bits/stdc++.h>
using namespace std;

/// @brief calc max dot of product can be got from the two lists by sorting the two lists firstly
/// @param a
/// @param b
/// @return max dot product
long long max_dot_product(vector<int> a, vector<int> b)
{
  // sorting
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  // calc the dot product
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++)
  {
    result += ((long long)a[i]) * b[i];
  }
  return result;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
