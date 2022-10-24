#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long NaiveGCD(int a, int b)
{
    long long gcd = 0;
    for (size_t i = 1; i <= min(a, b); i++)
    {
        if (i / a || i / b)
        {
            gcd = i;
        }
    }

    return gcd;
}

long long EuclidGCD(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return EuclidGCD(b % a, a);
    }
}

/// ** NOTE **
/// Euclidean GCD is very Faster then Naive GCD

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // choose the algorithm
    int t;
    cout << "Choose the algorithm to get GCD:" << endl;
    cout << "1. Naive\n2. Euclidean\nEnter any key to end" << endl;
    cin >> t;

    while (t == 1 || t == 2)
    {

        // input the two number
        long long a, b;
        cout << "Enter the two numbers" << endl;
        cin >> a >> b;

        auto start = high_resolution_clock::now();
        long long result = 0;
        if (t == 1)
        {
            result = NaiveGCD(a, b);
        }
        else if (t == 2)
        {
            result = EuclidGCD(a, b);
        }

        cout << "Result= " << result << endl;

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Execution Time: " << duration.count() << " microseconds" << endl;
        cout << "Execution Time: " << duration.count() / 1000 << " milliseconds"
             << "\n--------------------------------------------------\n";

        // choose the algorithm

        cout << "Choose the algorithm to get GCD:" << endl;
        cout << "1. Naive\n2. Euclidean\nEnter any key to end" << endl;
        cin >> t;
    }

    return 0;
}