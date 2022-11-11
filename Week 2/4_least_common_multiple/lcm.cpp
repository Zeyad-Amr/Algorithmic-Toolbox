#include <bits/stdc++.h>
using namespace std;

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
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

long long lcm_fast(int a, int b)
{
  if (a == 0)
  {
    return b;
  }
  else
  {
    return ((long long)a * b / gcd_fast(a, b));
  }
}

void test_function(int a, int b)
{
  for (size_t i = 1; i < 2; i++)
  {
    bool isTrue = lcm_fast(a * i, b * i) == lcm_naive(a * i, b * i);
    if (isTrue)
    {
      cout << lcm_fast(a * i, b * i) << endl;
    }
    else
    {
      cout << "Wrong at (" << a * i << ", " << b * i << ")=> " << lcm_fast(a * i, b * i) << " - " << lcm_naive(a * i, b * i) << endl;
      break;
    }
  }
  cout << "Finished" << endl;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << lcm_fast(a, b) << endl;
  // test_function(a, b);
  return 0;
}
