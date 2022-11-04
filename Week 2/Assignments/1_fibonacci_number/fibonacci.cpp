#include <bits/stdc++.h>
using namespace std;

// Fibonacci List Algorithm
long long FibList(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        vector<long long> fibList = {0, 1};

        for (int i = 2; i <= n; ++i)
        {
            fibList.push_back((long long)fibList.at(i - 1) + fibList.at(i - 2));
            cout << "F" << i << " => " << (long long)fibList.at(i - 1) + fibList.at(i - 2) << endl;
        }

        return fibList.back();
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 0;
    cin >> n;
    FibList(n) << '\n';
    return 0;
}
