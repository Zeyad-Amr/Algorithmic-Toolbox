#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A)
{
  int sum = 0;
  for (int i = 0; i < A.size(); i++)
  {
    sum += A[i];
  }
  if (sum % 3 != 0)
  {
    return 0;
  }
  int n = A.size();
  int W = sum / 3;

  vector<vector<int>> value(A.size() + 1, vector<int>(W + 1));
  for (int i = 1; i <= A.size(); i++)
  {
    for (int j = 1; j <= W; j++)
    {
      value[i][j] = value[i - 1][j];
      if (A[i - 1] <= j)
      {
        int val = value[i - 1][j - A[i - 1]] + A[i - 1];
        if (value[i][j] < val)
        {
          value[i][j] = val;
        }
      }
    }
  }

  if (value[n][W] == W)
  {
    return 1;
  }
  return 0;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
