#include <bits/stdc++.h>
using namespace std;

/// @brief binary search recursivly
/// @param a
/// @param left
/// @param right
/// @param x
/// @return element index
int binary_search_rec(const vector<int> &a, int left, int right, int x)
{
  // 1 2 3 4 5                l=0    r=
  if (right < left)
  {
    return -1;
  }

  int mid = floor(left + ((right - left) / 2));

  if (x == a[mid])
  {
    // getting the first occurence of the element
    int preMid = mid;
    while (x == a[preMid - 1])
    {
      preMid--;
    }

    return preMid;
  }
  else if (x < a[mid])
  {
    return binary_search_rec(a, left, mid - 1, x);
  }
  else
  {
    return binary_search_rec(a, mid + 1, right, x);
  }
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i)
  {
    // replace with the call to binary_search when implemented
    std::cout << binary_search_rec(a, 0, (int)a.size() - 1, b[i]) << ' ';
  }
}
