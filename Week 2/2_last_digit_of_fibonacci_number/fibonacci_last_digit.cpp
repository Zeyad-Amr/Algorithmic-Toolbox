#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

// Fibonacci Rule: Fn = Fn−1 + Fn−2.

long long LastDigitOfFibNum(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        vector<int> fibList = {0, 1};

        for (int i = 2; i <= n; ++i)
        {
            fibList.push_back((fibList.at(i - 1) + fibList.at(i - 2)) % 10);
        }

        return fibList.back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input n-th Fibonacci number
    int n;
    cin >> n;

    long long result = LastDigitOfFibNum(n);

    cout << result << endl;

    return 0;
}
