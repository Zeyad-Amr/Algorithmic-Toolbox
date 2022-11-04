#include <bits/stdc++.h>
using namespace std;

long long NaiveGCD(int a, int b)
{
    long long gcd = 0;
    int min_number = min(a, b);
    for (size_t i = 1; i <= min_number; i++)
    {
        if ((a % i == 0) && (b % i == 0))
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

test_function(a, b)
{
    cout << (EuclidGCD(a, b) == NaiveGCD(a, b)) << endl;
}
/// ** NOTE **
/// Euclidean GCD is very Faster then Naive GCD

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input the two number
    long long a, b;

    cin >> a >> b;

    long long result = EuclidGCD(a, b);

    cout << result << endl;

    return 0;
}