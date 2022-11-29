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
    return mid;
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

/// @brief binary search iterativly
/// @param a
/// @param left
/// @param right
/// @param x
/// @return element index
int binary_search_it(const vector<int> &a, int left, int right, int x)
{
  while (right >= left)
  {
    int mid = floor(left + ((right - left) / 2));
    if (x == a[mid])
    {
      return mid;
    }
    else if (x < a[mid])
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return -1;
}

/// @brief linear search
/// @param a
/// @param x
/// @return element index
int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

// /// @brief stress testing function

// void test_function(const vector<int> &a, int x)
// {

//   bool isTrue = linear_search(a, x) == binary_search_it(a, 0, (int)a.size(), x);
//   if (isTrue)
//   {
//     cout << binary_search_rec(a, 0, (int)a.size(), x) << " ";
//   }
//   else
//   {
//     cout << "Wrong at (" << x << ")=> " << linear_search(a, x) << " - " << binary_search_it(a, 0, (int)a.size(), x) << endl;
//   }
// }

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

    // std::cout << linear_search(a, b[i]) << ' ';

    std::cout << binary_search_rec(a, 0, (int)a.size() - 1, b[i]) << ' ';

    // test_function(a, b[i]);
  }
}
