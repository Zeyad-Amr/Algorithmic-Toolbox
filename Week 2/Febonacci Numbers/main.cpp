#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

// Fibonacci Rule: Fn = Fn−1 + Fn−2.

// Fibonacci Recursive Algorithm
long long FibRecursive(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return FibRecursive(n - 1) + FibRecursive(n - 2);
    }
}

// Fibonacci List Algorithm
long long FibList(int n)
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
            fibList.push_back(fibList.at(i - 1) + fibList.at(i - 2));
        }

        return fibList.back();
    }
}
// Another Algorithm for Fibonacci without recursion
// and without list
long long FibNum(int n)
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
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
}

/// ** NOTE **
/// Fiboacci List is very Faster then Fibonacci Recrsive

test_function(int n)
{
    cout << (FibList(n) == FibRecursive(n)) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input n-th Fibonacci number
    int n;
    cin >> n;

    int result = FibList(n);

    cout << result << endl;

    return 0;
}
