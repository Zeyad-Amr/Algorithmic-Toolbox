#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Use auto keyword to avoid typing long
    // type definitions to get the time-point
    // at this instant use function now()
    auto start = high_resolution_clock::now();

    // Function to be executed
    for (int i = 0; i < 1000; ++i) {
        cout<<i+1<<endl;
    }

    // After function call
    auto stop = high_resolution_clock::now();

    // Subtract stop and start time-points and
    // cast it to required unit. Predefined units
    // are nanoseconds, microseconds, milliseconds,
    // seconds, minutes, hours. Use duration_cast()
    // function.
    auto duration = duration_cast<microseconds>(stop - start);

    // To get the value of duration use the count()
    // member function on the duration object
    cout <<"Execution Time: "<< duration.count() <<" microseconds"<< endl;
    cout <<"Execution Time: "<< duration.count()/1000 <<" milliseconds"<< endl;
    cout <<"Execution Time: "<< duration.count()/1000000 <<" seconds"<< endl;


    return 0;
}