#include <bits/stdc++.h>
using namespace std;

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b)
{
  if (a == 0)
  {
    return b;
  }
  else
  {
    return gcd_fast(b % a, a);
  }
}

// void test_function(int a, int b)
// {
//   for (size_t i = 1; i < 100; i++)
//   {
//     bool isTrue = gcd_fast(a * i, b * i) == gcd_naive(a * i, b * i);
//     if (isTrue)
//     {
//       cout << gcd_fast(a * i, b * i) << endl;
//     }
//     else
//     {
//       cout << "Wrong at (" << a * i << ", " << b * i << ")=> " << gcd_fast(a * i, b * i) << " - " << gcd_naive(a * i, b * i) << endl;
//       break;
//     }
//   }
// cout << "Finished" << endl;
// }

int main()
{
  int a, b;
  cin >> a >> b;
  cout << gcd_fast(a, b) << endl;
  // test_function(a, b);
  return 0;
}
