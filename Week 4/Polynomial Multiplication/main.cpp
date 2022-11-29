#include <bits/stdc++.h>
using namespace std;

/// Polynomial Muliplication of n order
// highest degree = 2n-2
// terms from degree  0 to 2n-2
// size = 2n-1

/// @brief naive muliply polynomial  O(n^2)
/// @param a
/// @param b
/// @param n
/// @return product coe ffs
vector<int> mult_poly(vector<int> a, vector<int> b, int n)
{
    vector<int> product(2 * n - 1, 0);
    for (size_t i = 0; i <= n - 1; i++)
    {
        for (size_t j = 0; j <= n - 1; j++)
        {
            product[i + j] += (a[i] * b[j]);
        }
    }
    return product;
}

/// @brief stress testing function

// void test_function()
// {
//   for (size_t i = 1; i < 1000; i++)
//   {
//     bool isTrue = get_change_rec(i) == get_change_math(i);
//     if (isTrue)
//     {
//       cout << get_change_math(i) << endl;
//     }
//     else
//     {
//       cout << "Wrong at (" << i << ")=> " << get_change_rec(i) << " - " << get_change_math(i) << endl;
//       break;
//     }
//   }
//   cout << "Finished" << endl;
// }

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> result = mult_poly(a, b, n);
    for (size_t i = 0; i < 2 * n - 1; i++)
    {
        cout << result[i] << " ";
    }
}
