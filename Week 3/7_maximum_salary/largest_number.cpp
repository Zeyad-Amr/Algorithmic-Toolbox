#include <bits/stdc++.h>
using namespace std;

/// @brief comaring combnination order of two digits
/// @param digit
/// @param maxDigit
/// @return max combination value
bool isGreater(string digit, string maxDigit)
{

  string s1 = digit + maxDigit + "";
  string s2 = maxDigit + digit + "";

  return s1 > s2;
}

/// @brief struct for each number
struct element
{
  string s;
  // comparing opertator
  bool operator<(const element &a) const
  {
    return isGreater(s, a.s);
  }
};

/// @brief finaing the largest combination of the numbers
/// @param a
/// @return largest number
string largest_number(vector<string> a)
{
  vector<element> b(a.size());
  for (size_t i = 0; i < a.size(); i++)
  {
    b[i].s = a[i];
  }

  string result = "";

  sort(b.begin(), b.end());

  for (size_t i = 0; i < b.size(); i++)
  {
    result += b[i].s + "";
  }

  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
