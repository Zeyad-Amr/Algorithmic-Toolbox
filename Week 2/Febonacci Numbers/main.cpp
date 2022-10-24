#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

int FibRecursive(int n){
    if(n<=1){
        return n;
    }else{
        return FibRecursive(n-1)+ FibRecursive(n-2);
    }
}
int main() {



    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cout<<"Enter Fibonacci length"<<endl;
    cin>>n;

    auto start = high_resolution_clock::now();

    cout<<FibRecursive(n)<<endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Execution Time: "<< duration.count()<<" microseconds"<< endl;
    cout <<"Execution Time: "<< duration.count()/1000 <<" milliseconds"<< endl;

    return 0;
}