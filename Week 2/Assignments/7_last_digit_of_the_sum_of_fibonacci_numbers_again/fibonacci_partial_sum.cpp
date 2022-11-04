#include <bits/stdc++.h>
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
long long fibonacci_sum_fast(long long nn)
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
        current = (tmp_previous + current) % 10;
        sum += current;
    }

    return (long long)sum + (nn / 60) * 280;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to)
{
    long long too = fibonacci_sum_fast(to);
    long long fromm = fibonacci_sum_fast(from - 1);
    long long result = (too - fromm) % 10;
    // cout << too << ", " << fromm << ", " << result << '\n';
    return result;
}

void test_function()
{
    for (size_t i = 0; i < 100; i++)
    {
        bool isTrue = get_fibonacci_partial_sum_fast(i, (i * 2) + 15) == get_fibonacci_partial_sum_naive(i, (i * 2) + 15);
        if (isTrue)
        {
            cout << "index: " << i << " => " << get_fibonacci_partial_sum_fast(i, (i * 2) + 15) << endl;
        }
        else
        {
            cout << "Wrong at " << i << " => " << get_fibonacci_partial_sum_fast(i, (i * 2) + 15) << " - " << get_fibonacci_partial_sum_naive(i, (i * 2) + 15) << endl;
            // break;
        }
    }
    cout << "Finished" << endl;
}

int main()
{
    long long from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_fast(from, to) << '\n';

    // test_function();
    // cout << get_fibonacci_partial_sum_fast(10, 200) << endl;
}
