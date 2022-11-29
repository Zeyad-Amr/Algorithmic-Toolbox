#include <bits/stdc++.h>
using namespace std;

/// @brief getting the maximun value of the items
/// @param costs
/// @param weights
/// @return index of max value item
int get_max_value_index(vector<int> costs, vector<int> weights)
{
  double max = (double)costs[0] / weights[0];
  int maxIndex = 0;
  for (size_t i = 1; i < costs.size(); i++)
  {
    double value = (double)costs[i] / weights[i];
    if (max <= value)
    {
      max = value;
      maxIndex = i;
    }
  }
  return maxIndex;
}

/// @brief greedy calc the maximun value of the loot recursively
/// @param capacity
/// @param weights
/// @param costs
/// @return optimal value
double get_optimal_value_rec(int capacity, vector<int> weights, vector<int> costs)
{
  if (capacity == 0 || weights.size() == 0)
  {
    return 0;
  }
  else
  {
    int m = get_max_value_index(costs, weights);

    int amount = min(weights[m], capacity);
    double value = costs[m] * ((double)amount / weights[m]);
    capacity -= amount;

    // cout << "index: " << costs[m] << ", amount: " << amount << ", capacity: " << capacity << endl;

    weights.erase(weights.begin() + m);
    costs.erase(costs.begin() + m);

    return value + get_optimal_value_rec(capacity, weights, costs);
  }
}

/// @brief greedy calc the maximun value of the loot iteratively
/// @param capacity
/// @param weights
/// @param costs
/// @return optimal value
double get_optimal_value_iter(int capacity, vector<int> weights, vector<int> costs)
{
  double value = 0;
  while (capacity != 0 || weights.size() != 0)
  {
    int m = get_max_value_index(costs, weights);

    int amount = min(weights[m], capacity);
    value += costs[m] * ((double)amount / weights[m]);
    capacity -= amount;

    // cout << "index: " << costs[m] << ", amount: " << amount << ", capacity: " << capacity << endl;

    weights.erase(weights.begin() + m);
    costs.erase(costs.begin() + m);
  }
  return value;
}

/// @brief stress testing function
void test_function(int n, int length)
{
  int i = 0;
  while (i < length)
  {
    int capactiy = rand() % 100 + 10;
    cout << n << " " << capactiy << endl;
    vector<int> w;
    vector<int> c;
    for (size_t i = 0; i < n; i++)
    {
      w.push_back(rand() % 300 + 50);
      c.push_back(rand() % 300 + 50);

      cout << c[i] << " " << w[i] << endl;
    }

    long long res1 = get_optimal_value_iter(capactiy, w, c);
    long long res2 = get_optimal_value_rec(capactiy, w, c);
    if (res1 != res2)
    {
      cout << "Wrong at => " << res1 << " - " << res2 << endl;
      break;
    }
    else
    {
      cout << "OK: " << res1 << endl;
    }
    i++;
  }

  cout << "Finished" << endl;
}

int main()
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> costs(n);
  vector<int> weights(n);

  for (int i = 0; i < n; i++)
  {
    cin >> costs[i] >> weights[i];
  }

  double optimal_value = get_optimal_value_rec(capacity, weights, costs);

  cout.precision(10);
  cout << optimal_value << endl;

  // test_function(3, 100);
  return 0;
}