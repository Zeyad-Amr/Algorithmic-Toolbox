#include <bits/stdc++.h>
using namespace std;

/// @brief calc min number of refuels for moving from city to another
/// @param dist distance bt two cities
/// @param tank max tank capacity
/// @param stops list of fuel stops
/// @return no of refuels
int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    int max_dis = tank;
    int location = 0;
    int refuels = 0;
    stops.push_back(dist);
    for (size_t i = 0; i < stops.size(); i++)
    {
        int distance_to_next_stop = stops[i] - location;
        if (distance_to_next_stop <= tank)
        {
            location = stops[i];
            tank -= distance_to_next_stop;
        }
        else if (distance_to_next_stop <= max_dis)
        {
            location = stops[i];
            tank = max_dis;
            tank -= distance_to_next_stop;
            refuels++;
        }
        else
        {
            return -1;
        }
    }
    return refuels;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}