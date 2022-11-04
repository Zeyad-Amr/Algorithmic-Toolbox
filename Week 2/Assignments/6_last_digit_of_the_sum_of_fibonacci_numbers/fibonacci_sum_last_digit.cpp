#include <bits/stdc++.h>
using namespace std;

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n)
{
    // 60 => pisano period length for mod 10
    // to decrease number of iterations
    // as c++ data types can not store the large fib numbers
    n = n % 60;
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current;
        sum %= 10;
    }

    return sum;
}

void test_function()
{
    for (size_t i = 1; i < 250; i++)
    {
        bool isTrue = fibonacci_sum_fast(i) == fibonacci_sum_naive(i);
        if (isTrue)
        {
            cout << fibonacci_sum_fast(i) << endl;
        }
        else
        {
            cout << "Wrong at " << i << " => " << fibonacci_sum_fast(i) << " - " << fibonacci_sum_naive(i) << endl;
            break;
        }
    }
    cout << "Finished" << endl;
}

int main()
{
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_fast(n);
    // test_function();
}
