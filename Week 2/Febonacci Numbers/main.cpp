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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // choose the algorithm
    int t;
    cout << "Choose the algorithm to get Fibonacci Number:" << endl;
    cout << "1. Fibonacci Recursive\n2. Fibonacci List\nEnter any key to end" << endl;
    cin >> t;

    while (t == 1 || t == 2)
    {

        // input n-th Fibonacci number
        int n;
        cout << "Enter n-th Fibonacci number" << endl;
        cin >> n;

        auto start = high_resolution_clock::now();
        long long result = 0;
        if (t == 1)
        {
            result = FibRecursive(n);
        }
        else if (t == 2)
        {
            result = FibList(n);
        }

        cout << "Result= " << FibRecursive(n) << endl;

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Execution Time: " << duration.count() << " microseconds" << endl;
        cout << "Execution Time: " << duration.count() / 1000 << " milliseconds"
             << "\n--------------------------------------------------\n";

        // choose the algorithm
        t;
        cout << "Choose the algorithm to get Fibonacci Number:" << endl;
        cout << "1. Fibonacci Recursive\n2. Fibonacci List" << endl;
        cin >> t;
    }

    return 0;
}