#include <bits/stdc++.h>
using namespace std;

int lcs2(vector<int> &a, vector<int> &b)
{

  vector<vector<int>> sequences(a.size() + 1, vector<int>(b.size() + 1));

  for (int i = 0; i <= a.size(); i++)
  {
    for (int j = 0; j <= b.size(); j++)
    {
      if (i == 0 || j == 0)
      {
        sequences[i][j] = 0;
      }
      else if (a[i - 1] == b[j - 1])
      {
        sequences[i][j] = sequences[i - 1][j - 1] + 1;
      }
      else
      {
        sequences[i][j] = max(sequences[i - 1][j], sequences[i][j - 1]);
      }
    }
  }

  return sequences[a.size()][b.size()];
}

int main()
{
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  cout << lcs2(a, b) << endl;
}
