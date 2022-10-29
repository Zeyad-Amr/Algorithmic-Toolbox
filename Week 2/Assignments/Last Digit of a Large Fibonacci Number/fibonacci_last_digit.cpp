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
        int n1 = 0, n2 = 1, n3;
        for (int i = 2; i <= n; ++i)
        {
            n3 = (n1 + n2) % 10;
            n1 = n2;
            n2 = n3;
        }
        return n3;
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
