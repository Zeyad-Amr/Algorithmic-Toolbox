#include <bits/stdc++.h>
using namespace std;

int get_fibonacci(long long n)
{
    n = n % 60;
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 60;
    }

    return current;
}

int fibonacci_sum_squares_naive(long long n)
{

    return (get_fibonacci(n) * get_fibonacci(n + 1)) % 10;
}

long long fibonacci_sum_squares_fast_helper(long long nn)
{
    // 60 => pisano period length for mod 10
    // to decrease number of iterations
    // as c++ data types can not store the large fib numbers
    int n = nn % 60;
    if (n < 1)
        return 0;
    if (n == 1)
        return 1;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 2; i < n + 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 60;
    }

    return current;
}

long long fibonacci_sum_squares_fast(long long n)
{
    // as F(i) * F(i+1) = F(0)^2 + F(1)^2 + ..... + F(i)^2
    return (fibonacci_sum_squares_fast_helper(n) * fibonacci_sum_squares_fast_helper(n + 1)) % 10;
}

void test_function()
{
    for (size_t i = 0; i < 100; i++)
    {
        bool isTrue = fibonacci_sum_squares_fast(i) == fibonacci_sum_squares_naive(i);
        if (isTrue)
        {
            cout << "index: " << i << " => " << fibonacci_sum_squares_fast(i) << endl;
        }
        else
        {
            cout << "Wrong at " << i << " => " << fibonacci_sum_squares_fast(i) << " - " << fibonacci_sum_squares_naive(i) << endl;
            // break;
        }
    }
    cout << "Finished" << endl;
}
int main()
{
    long long n = 0;
    cin >> n;
    cout << fibonacci_sum_squares_fast(n);

    // test_function();
}
