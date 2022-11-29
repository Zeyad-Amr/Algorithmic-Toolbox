#include <bits/stdc++.h>
using namespace std;

/// @brief  comparing between to points according to X
/// @param a
/// @param b
/// @return is Smaller than X?
bool is_smaller_than_X(pair<long long, long long> &a, pair<long long, long long> &b)
{
  if (a.first == b.first)
  {

    return a.second < b.second;
  }
  else
  {
    return a.first < b.first;
  };
}

/// @brief  comparing between to points according to Y
/// @param a
/// @param b
/// @return is Smaller than Y?
bool is_smaller_than_Y(pair<long long, long long> &a, pair<long long, long long> &b)
{

  if (a.second == b.second)
  {

    return a.first < b.first;
  }
  else
  {
    return a.second < b.second;
  };
}

/// @brief calc distace between two points
/// @param a
/// @param b
/// @return get_distance
double get_distance(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
  return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}

/// @brief merge sort algorithm
/// @param points
/// @param left
/// @param right
void merge(vector<pair<long long, long long>> &points, long long left, long long right)
{
  if (left >= right)
    return;

  long long mid = left + (right - left) / 2;
  long long i = left, j = mid + 1;
  vector<pair<long long, long long>> vec;
  vec.reserve(right - left + 1);

  while (i <= mid && j <= right)
  {
    if (is_smaller_than_Y(points[i], points[j]))
    {
      vec.emplace_back(points[i].first, points[i].second);
      i++;
    }
    else
    {
      vec.emplace_back(points[j].first, points[j].second);
      j++;
    }
  }
  while (i <= mid)
  {
    vec.emplace_back(points[i].first, points[i].second);
    i++;
  }
  while (j <= right)
  {
    vec.emplace_back(points[j].first, points[j].second);
    j++;
  }

  for (size_t k = 0; k < vec.size(); k++)
  {
    points[left + k] = vec.at(k);
  }
}

/// @brief calculating the minimal distance bt two points from array of points
/// @param points
/// @param left
/// @param right
/// @return minimal distance
double minimal_distance(vector<pair<long long, long long>> &points, long long left, long long right)
{
  if (left >= right)
    return numeric_limits<double>::max();
  if (right - left == 1)
  {
    if (!is_smaller_than_Y(points[left], points[right]))
    {
      swap(points[left], points[right]);
    }
    return get_distance(points[left], points[right]);
  }

  long long mid = left + (right - left) / 2;
  auto mid_point = points.at(mid);

  double d = min(minimal_distance(points, left, mid), minimal_distance(points, mid + 1, right));

  vector<pair<long long, long long>> side_points;

  merge(points, left, right);
  for (long long i = left; i <= right; i++)
  {
    if (abs(points[i].first - mid_point.first) <= d)
    {
      side_points.emplace_back(points[i].first, points[i].second);
    }
  }

  for (long long i = 0; i < side_points.size() - 1; i++)
  {
    for (long long j = i + 1; j < side_points.size() && j - i < 8; j++)
    {
      d = min(d, get_distance(side_points[i], side_points[j]));
    }
  }

  return d;
}

int main()
{
  size_t n;
  cin >> n;
  vector<pair<long long, long long>> points(n);
  long long x, y;
  for (size_t i = 0; i < n; i++)
  {
    cin >> x >> y;
    points[i] = make_pair(x, y);
  }

  // sorting points firstly
  sort(points.begin(), points.end(), is_smaller_than_X);

  cout << setprecision(9) << minimal_distance(points, 0, points.size() - 1) << endl;
}

/* Tests

11
4 4
-2 -2
-3 -4
-1 3
2 3
-4 0
1 1
-1 -1
3 -1
-4 2
-2 4

 */