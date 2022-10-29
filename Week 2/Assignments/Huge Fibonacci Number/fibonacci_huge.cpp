#include <iostream>

//  calc Pisano period length
long pisanoPeriodLength(long m)
{
    long previous = 0;
    long current = 1;
    long count = 0;

    for (int i = 0; i < m * m; i++)
    {
        long temp = 0;
        temp = current;
        current = (previous + current) % m;
        previous = temp;

        if (previous == 0 && current == 1)
            count = i + 1;
    }
    return count;
}

long long get_fibonacci_huge(long long n, long long m)
{
    // Firsy calc pisano period length
    // for the mod to simplify the mod value

    n = n % pisanoPeriodLength(m);
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
