#include <bits/stdc++.h>
using namespace std;

/// @brief segment structure
struct Segment
{
  int start, end;
  // comparing opertator
  bool operator<(const Segment &a) const
  {
    return end < a.end;
  }
};
/// @brief getting the min no of points to visit all the lines
/// @param segments
/// @return min no. of points
vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  // sorting segments wrt end
  sort(segments.begin(), segments.end());

  for (size_t i = 0; i < segments.size(); ++i)
  {
    if (points.empty())
    {
      points.push_back(segments[i].end);
    }
    else if (points.back() < segments[i].start || points.back() > segments[i].end)
    {
      points.push_back(segments[i].end);
    }
  }

  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
